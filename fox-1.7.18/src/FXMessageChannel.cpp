/********************************************************************************
*                                                                               *
*         I n t e r - T h r e a d    M e s s a g i n g    C h a n n e l         *
*                                                                               *
*********************************************************************************
* Copyright (C) 2006,2008 by Jeroen van der Zijp.   All Rights Reserved.        *
*********************************************************************************
* This library is free software; you can redistribute it and/or modify          *
* it under the terms of the GNU Lesser General Public License as published by   *
* the Free Software Foundation; either version 3 of the License, or             *
* (at your option) any later version.                                           *
*                                                                               *
* This library is distributed in the hope that it will be useful,               *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                 *
* GNU Lesser General Public License for more details.                           *
*                                                                               *
* You should have received a copy of the GNU Lesser General Public License      *
* along with this program.  If not, see <http://www.gnu.org/licenses/>          *
*********************************************************************************
* $Id: FXMessageChannel.cpp,v 1.15 2008/08/29 16:43:52 fox Exp $                *
********************************************************************************/
#include "xincs.h"
#include "fxver.h"
#include "fxdefs.h"
#include "FXException.h"
#include "FXHash.h"
#include "FXThread.h"
#include "FXStream.h"
#include "FXString.h"
#include "FXSize.h"
#include "FXPoint.h"
#include "FXRectangle.h"
#include "FXRegistry.h"
#include "FXApp.h"
#include "FXMessageChannel.h"


/*
  Notes:
  - Inter-thread messaging is handy to have.
  - Redo this in terms of FXPipe when that becomes possible.
  - Because of unbelievably retarded design of Windows, we need to
    use an Event-object to actually signal the GUI thread when we've
    written something to the pipe.
  - Based on suggestion from Axel Schmidt <axel.schmidt@analytica-karlsruhe.de>,
    the Event object was replaced by counting Semaphore.  
    This way, the number of calls to message() has to be equal to the number of calls 
    to MsgWaitForMultipleObjects.  Thus, each call to message() results in exactly
    one callback in the GUI thread.
*/


// Maximum message size
#define MAXMESSAGE 8192

// Bad handle value
#ifdef WIN32
#define BadHandle  INVALID_HANDLE_VALUE
#else
#define BadHandle  -1
#endif


using namespace FX;


/*******************************************************************************/

namespace FX {


// Structure of message
struct FXMessage {
  FXObject  *target;            // Message target
  FXSelector message;           // Message type,id
#if !(defined(__LP64__) || defined(_LP64) || (_MIPS_SZLONG == 64) || (__WORDSIZE == 64) || defined(_WIN64))
  FXint      pad;               // Padding for 32-bit
#endif
  FXint      size;              // Message size
  };


// Structure of message+payload
struct FXDataMessage {
  FXObject  *target;            // Message target
  FXSelector message;           // Message type,id
#if !(defined(__LP64__) || defined(_LP64) || (_MIPS_SZLONG == 64) || (__WORDSIZE == 64) || defined(_WIN64))
  FXint      pad;               // Padding for 32-bit
#endif
  FXint      size;              // Message size
  FXlong     data[MAXMESSAGE/sizeof(FXlong)];
  };


// Map
FXDEFMAP(FXMessageChannel) FXMessageChannelMap[]={
  FXMAPFUNC(SEL_IO_READ,FXMessageChannel::ID_IO_READ,FXMessageChannel::onMessage)
  };


// Object implementation
FXIMPLEMENT(FXMessageChannel,FXObject,FXMessageChannelMap,ARRAYNUMBER(FXMessageChannelMap));


// Initialize to empty
FXMessageChannel::FXMessageChannel():app((FXApp*)-1L){
  h[0]=h[1]=h[2]=BadHandle;
  }


// Add handler to application
FXMessageChannel::FXMessageChannel(FXApp* a):app(a){
#ifdef WIN32
  if((h[2]=::CreateSemaphore(NULL,0,2147483647,NULL))==NULL){ throw FXResourceException("unable to create semaphore."); }
  if(::CreatePipe(&h[0],&h[1],NULL,0)==0){ throw FXResourceException("unable to create pipe."); }
  app->addInput(this,ID_IO_READ,h[2],INPUT_READ,NULL);
#else
  if(::pipe(h)!=0){ throw FXResourceException("unable to create pipe."); }
  ::fcntl(h[0],F_SETFD,FD_CLOEXEC);
  ::fcntl(h[1],F_SETFD,FD_CLOEXEC);
  app->addInput(this,ID_IO_READ,h[0],INPUT_READ,NULL);
#endif
  }


// Fire signal message to target
long FXMessageChannel::onMessage(FXObject*,FXSelector,void*){
  FXDataMessage pkg;
#ifdef WIN32
  DWORD nread=-1;
  if(::ReadFile(h[0],&pkg,sizeof(FXMessage),&nread,NULL) && nread==sizeof(FXMessage)){
    if(0<pkg.size && (::ReadFile(h[0],pkg.data,pkg.size,&nread,NULL) && nread==pkg.size)){
      return pkg.target && pkg.target->tryHandle(this,pkg.message,pkg.data);
      }
    return pkg.target && pkg.target->tryHandle(this,pkg.message,NULL);
    }
#else
  if(::read(h[0],&pkg,sizeof(FXMessage))==sizeof(FXMessage)){
    if(0<pkg.size && (::read(h[0],pkg.data,pkg.size)==pkg.size)){
      return pkg.target && pkg.target->tryHandle(this,pkg.message,pkg.data);
      }
    return pkg.target && pkg.target->tryHandle(this,pkg.message,NULL);
    }
#endif
  return 0;
  }


// Send a message to a target
FXbool FXMessageChannel::message(FXObject* tgt,FXSelector msg,const void* data,FXint size){
  FXMutexLock locker(m);
  FXMessage pkg;
  pkg.target=tgt;
  pkg.message=msg;
#if !(defined(__LP64__) || defined(_LP64) || (_MIPS_SZLONG == 64) || (__WORDSIZE == 64) || defined(_WIN64))
  pkg.pad=0;
#endif
  pkg.size=size;
#ifdef WIN32
  DWORD nwritten=-1;
  if(::WriteFile(h[1],&pkg,sizeof(FXMessage),&nwritten,NULL) && nwritten==sizeof(FXMessage)){
    if(pkg.size<=0 || (::WriteFile(h[1],data,pkg.size,&nwritten,NULL) && nwritten==pkg.size)){
      ::ReleaseSemaphore(h[2],1,NULL);
      return true;
      }
    }
#else
  if(::write(h[1],&pkg,sizeof(FXMessage))==sizeof(FXMessage)){
    if(pkg.size<=0 || (::write(h[1],data,pkg.size)==pkg.size)){
      return true;
      }
    }
#endif
  return false;
  }


// Remove handler from application
FXMessageChannel::~FXMessageChannel(){
#ifdef WIN32
  app->removeInput(h[2],INPUT_READ);
  ::CloseHandle(h[0]);
  ::CloseHandle(h[1]);
  ::CloseHandle(h[2]);
#else
  app->removeInput(h[0],INPUT_READ);
  ::close(h[0]);
  ::close(h[1]);
#endif
  app=(FXApp*)-1L;
  }

}
