// Copyright (C) 2005 Open Source Telecom Corp.
//  
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software 
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

#include "driver.h"
#ifdef	HAVE_FOX

#include <fx.h>
#include <fxkeys.h>

namespace scdriver {
using namespace ost;
using namespace std;

/* Generated by reswrap version 3.2.0 */

/* created by reswrap from file /Users/dyfet/packaging/icons/bayonne-large.gif */
const unsigned char bayonnelarge[]={
  0x47,0x49,0x46,0x38,0x39,0x61,0x40,0x00,0x40,0x00,0xf7,0x00,0x00,0x00,0x00,0x00,
  0x04,0x04,0x04,0x05,0x05,0x05,0x07,0x07,0x07,0x08,0x08,0x08,0x09,0x09,0x09,0x0a,
  0x0a,0x0a,0x0b,0x0b,0x0b,0x0d,0x0d,0x0d,0x0e,0x0e,0x0e,0x0f,0x0f,0x0f,0x10,0x10,
  0x10,0x11,0x11,0x11,0x12,0x12,0x12,0x14,0x14,0x14,0x15,0x15,0x15,0x17,0x17,0x17,
  0x19,0x19,0x19,0x1a,0x1a,0x1a,0x1b,0x1b,0x1b,0x1c,0x1c,0x1c,0x1e,0x1e,0x1e,0x1f,
  0x1f,0x1f,0x21,0x21,0x21,0x22,0x22,0x22,0x23,0x23,0x23,0x24,0x24,0x24,0x26,0x26,
  0x26,0x27,0x27,0x27,0x28,0x28,0x28,0x29,0x29,0x29,0x2a,0x2a,0x2a,0x2c,0x2c,0x2c,
  0x2d,0x2d,0x2d,0x2e,0x2e,0x2e,0x2f,0x2f,0x2f,0x30,0x30,0x30,0x33,0x33,0x33,0x34,
  0x34,0x34,0x35,0x35,0x35,0x37,0x37,0x37,0x38,0x38,0x38,0x39,0x39,0x39,0x3a,0x3a,
  0x3a,0x3c,0x3c,0x3c,0x3d,0x3d,0x3d,0x3f,0x3f,0x3f,0x41,0x41,0x41,0x42,0x42,0x42,
  0x43,0x43,0x43,0x44,0x44,0x44,0x45,0x45,0x45,0x46,0x46,0x46,0x48,0x48,0x48,0x49,
  0x49,0x49,0x4a,0x4a,0x4a,0x4b,0x4b,0x4b,0x4c,0x4c,0x4c,0x4d,0x4d,0x4d,0x4e,0x4e,
  0x4e,0x4f,0x4f,0x4f,0x50,0x50,0x50,0x53,0x53,0x53,0x54,0x54,0x54,0x55,0x55,0x55,
  0x56,0x56,0x56,0x59,0x59,0x59,0x5a,0x5a,0x5a,0x5b,0x5b,0x5b,0x5c,0x5c,0x5c,0x5d,
  0x5d,0x5d,0x5f,0x5f,0x5f,0x60,0x60,0x60,0x61,0x61,0x61,0x62,0x62,0x62,0x63,0x63,
  0x63,0x65,0x65,0x65,0x66,0x66,0x66,0x67,0x67,0x67,0x69,0x69,0x69,0x6a,0x6a,0x6a,
  0x6b,0x6b,0x6b,0x6d,0x6d,0x6d,0x6e,0x6e,0x6e,0x6f,0x6f,0x6f,0x70,0x70,0x70,0x71,
  0x71,0x71,0x72,0x72,0x72,0x73,0x73,0x73,0x74,0x74,0x74,0x75,0x75,0x75,0x76,0x76,
  0x76,0x77,0x77,0x77,0x78,0x78,0x78,0x79,0x79,0x79,0x7a,0x7a,0x7a,0x7b,0x7b,0x7b,
  0x7c,0x7c,0x7c,0x7d,0x7d,0x7d,0x7e,0x7e,0x7e,0x81,0x81,0x81,0x82,0x82,0x82,0x83,
  0x83,0x83,0x84,0x84,0x84,0x86,0x86,0x86,0x87,0x87,0x87,0x88,0x88,0x88,0x8a,0x8a,
  0x8a,0x8b,0x8b,0x8b,0x8c,0x8c,0x8c,0x8e,0x8e,0x8e,0x8f,0x8f,0x8f,0x90,0x90,0x90,
  0x91,0x91,0x91,0x92,0x92,0x92,0x93,0x93,0x93,0x94,0x94,0x94,0x95,0x95,0x95,0x97,
  0x97,0x97,0x98,0x98,0x98,0x9a,0x9a,0x9a,0x9b,0x9b,0x9b,0x9c,0x9c,0x9c,0x9d,0x9d,
  0x9d,0x9e,0x9e,0x9e,0x9f,0x9f,0x9f,0xa1,0xa1,0xa1,0xa2,0xa2,0xa2,0xa3,0xa3,0xa3,
  0xa5,0xa5,0xa5,0xa6,0xa6,0xa6,0xa7,0xa7,0xa7,0xa8,0xa8,0xa8,0xa9,0xa9,0xa9,0xaa,
  0xaa,0xaa,0xab,0xab,0xab,0xac,0xac,0xac,0xae,0xae,0xae,0xaf,0xaf,0xaf,0xb0,0xb0,
  0xb0,0xb1,0xb1,0xb1,0xb2,0xb2,0xb2,0xb3,0xb3,0xb3,0xb4,0xb4,0xb4,0xb5,0xb5,0xb5,
  0xb6,0xb6,0xb6,0xb7,0xb7,0xb7,0xb9,0xb9,0xb9,0xba,0xba,0xba,0xbb,0xbb,0xbb,0xbc,
  0xbc,0xbc,0xbe,0xbe,0xbe,0xbf,0xbf,0xbf,0xc0,0xc0,0xc0,0xc1,0xc1,0xc1,0xc3,0xc3,
  0xc3,0xc4,0xc4,0xc4,0xc5,0xc5,0xc5,0xc6,0xc6,0xc6,0xc7,0xc7,0xc7,0xc8,0xc8,0xc8,
  0xc9,0xc9,0xc9,0xcb,0xcb,0xcb,0xce,0xce,0xce,0xd0,0xd0,0xd0,0xd2,0xd2,0xd2,0xd3,
  0xd3,0xd3,0xd4,0xd4,0xd4,0xd5,0xd5,0xd5,0xd6,0xd6,0xd6,0xd7,0xd7,0xd7,0xd8,0xd8,
  0xd8,0xd9,0xd9,0xd9,0xda,0xda,0xda,0xdb,0xdb,0xdb,0xdc,0xdc,0xdc,0xdd,0xdd,0xdd,
  0xdf,0xdf,0xdf,0xe0,0xe0,0xe0,0xe1,0xe1,0xe1,0xe2,0xe2,0xe2,0xe3,0xe3,0xe3,0xe4,
  0xe4,0xe4,0xe5,0xe5,0xe5,0xe6,0xe6,0xe6,0xe7,0xe7,0xe7,0xe8,0xe8,0xe8,0xe9,0xe9,
  0xe9,0xed,0xed,0xed,0xf1,0xf1,0xf1,0xf3,0xf3,0xf3,0xf7,0xf7,0xf7,0xff,0xff,0xff,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x21,0xf9,0x04,
  0x01,0x00,0x00,0xc1,0x00,0x2c,0x00,0x00,0x00,0x00,0x40,0x00,0x40,0x00,0x00,0x08,
  0xff,0x00,0x35,0x09,0x1c,0x48,0xb0,0xa0,0xc1,0x83,0x08,0x13,0x2a,0x5c,0xc8,0xb0,
  0xa1,0xc3,0x87,0x10,0x23,0x4a,0x9c,0x48,0xb1,0xa2,0xc5,0x8b,0x18,0x33,0x6a,0xdc,
  0xc8,0xb1,0xa3,0xc7,0x8f,0x20,0x43,0x8a,0x1c,0x49,0xb2,0xa4,0xc9,0x93,0x28,0x53,
  0xaa,0x5c,0xc9,0xb2,0xa5,0xcb,0x95,0xac,0x42,0x7d,0xf2,0x24,0xaa,0xd4,0xac,0x97,
  0x05,0x43,0x45,0x3a,0x85,0x33,0x61,0xaf,0x44,0x49,0x74,0x04,0x7a,0x88,0x0b,0xd5,
  0xad,0x93,0x9b,0x9a,0x54,0x68,0x70,0x66,0x22,0x2f,0x56,0x23,0x7d,0xf5,0x69,0x31,
  0x20,0x40,0x08,0x4f,0x3d,0x0d,0xfa,0x7a,0xb3,0x01,0x80,0xd7,0x19,0xb6,0xb2,0x16,
  0x84,0x63,0x21,0x80,0x57,0x00,0x3a,0xc4,0x12,0x14,0xe4,0xe1,0xec,0x57,0xb5,0x02,
  0x43,0xc1,0x30,0xeb,0x96,0x04,0x2f,0xb5,0xbe,0xb0,0x14,0x70,0xeb,0x15,0x02,0x2a,
  0xb5,0x8b,0x32,0xf0,0xf5,0x2a,0x60,0x68,0xd6,0x5d,0x4c,0x0c,0x0c,0x06,0x10,0x00,
  0x89,0x58,0x4c,0x20,0x02,0xd0,0xe5,0x5b,0x81,0x56,0x56,0x34,0x0b,0xf6,0x2e,0x06,
  0x90,0xa7,0xe7,0x2c,0x28,0x63,0x3a,0xb5,0xa2,0xb4,0x04,0x01,0xdf,0x14,0x3d,0x53,
  0x09,0xd2,0x55,0x90,0x53,0x09,0xb7,0x8c,0x7a,0xb2,0x3e,0xb8,0xeb,0x07,0x63,0x16,
  0x70,0x11,0x36,0x29,0xdc,0x33,0xd4,0x20,0x41,0x86,0x08,0x55,0x3a,0x58,0x26,0xab,
  0x2e,0x2e,0x08,0x2e,0x75,0xe2,0xb1,0xa2,0x57,0xee,0x81,0x80,0x16,0xdc,0x24,0x25,
  0xa0,0xd0,0x73,0x81,0x82,0x16,0x58,0x56,0x35,0x00,0x92,0xa6,0x4c,0x53,0xb6,0x04,
  0xff,0xf1,0xa3,0x09,0x0d,0x91,0x2b,0x58,0x49,0x6d,0x81,0xa3,0x49,0x12,0x13,0x35,
  0x4d,0x06,0xa2,0x31,0x12,0x88,0x52,0x8f,0x16,0x80,0x34,0xc9,0xea,0x52,0x64,0xd3,
  0x1f,0x19,0x32,0x10,0x54,0x09,0x18,0x65,0x84,0xb1,0xd0,0x20,0x0c,0xc8,0xa2,0x09,
  0x17,0x39,0x08,0x54,0x43,0x7e,0x9f,0x1c,0x20,0x0a,0x2f,0x16,0x54,0x31,0x10,0x1b,
  0xb8,0x1c,0x32,0x81,0x2b,0x9a,0x94,0xe2,0x00,0x26,0x02,0x7d,0xd0,0x82,0x19,0xaf,
  0xd0,0xf1,0x40,0x2c,0x9a,0xe4,0x62,0x00,0x0f,0x76,0xcc,0x22,0xc5,0x07,0x02,0x49,
  0x32,0x82,0x40,0x4e,0x68,0xa1,0xd0,0x20,0x07,0x68,0x01,0xc3,0x0d,0x96,0x69,0xb2,
  0xca,0x40,0x07,0x1c,0xa2,0x89,0x17,0x17,0x38,0xe7,0x4b,0x1c,0x9a,0x9c,0x10,0xc5,
  0x40,0x44,0xc0,0x20,0x90,0x0a,0x52,0x08,0xc4,0x8a,0x01,0x96,0x08,0xe4,0x80,0x1e,
  0x02,0x25,0x52,0x80,0x73,0x31,0x38,0x21,0xd0,0x1d,0x18,0xdc,0xa8,0x00,0x2c,0xbd,
  0x8c,0xc1,0x81,0x29,0x02,0x0d,0x92,0x46,0x1a,0x04,0x18,0xa2,0xc9,0x29,0x09,0xe4,
  0x67,0x48,0x2a,0xba,0x2c,0x60,0xc7,0x40,0x69,0x44,0x20,0x50,0x0a,0x59,0x08,0xf4,
  0x8a,0x01,0xc3,0x69,0xf2,0x80,0x20,0x02,0x39,0x22,0xc0,0x2e,0x9a,0x44,0x40,0x43,
  0x1c,0x72,0x50,0x31,0x83,0x73,0x08,0x09,0x92,0x40,0x2d,0x02,0x99,0x20,0x84,0x26,
  0x38,0x14,0x51,0x8b,0x2e,0x05,0xb8,0xa9,0x49,0x0e,0x2f,0x68,0xd2,0x86,0x26,0xb8,
  0x28,0x80,0xc7,0x40,0x6b,0x38,0xb0,0x67,0x9f,0x9a,0xc0,0x52,0x40,0xa0,0x0e,0x0c,
  0xc9,0x52,0xa8,0x00,0x77,0x41,0x60,0x63,0x43,0x92,0x52,0xfa,0xe9,0x0b,0x9c,0x08,
  0x00,0x8a,0x40,0x02,0x78,0xaa,0xc8,0x01,0x6f,0x74,0x12,0x22,0x17,0x03,0x35,0x81,
  0xc2,0xaa,0x02,0xb9,0x0a,0xab,0xac,0x9a,0x18,0xea,0x9c,0x0b,0x3b,0x38,0x94,0xc7,
  0x02,0x0a,0x9a,0x22,0xc1,0x1a,0xa3,0x0c,0x30,0x47,0x87,0x0a,0xf0,0x31,0x90,0x07,
  0x38,0x0c,0xe4,0x46,0x07,0xce,0xd9,0x42,0xc1,0x1f,0x02,0x8d,0x40,0x85,0x40,0xab,
  0x14,0xf0,0x88,0x40,0x08,0xf4,0x21,0xd0,0x21,0x01,0x84,0xd5,0x08,0x04,0x93,0x30,
  0xd4,0x88,0x0f,0x22,0x3c,0xf1,0x05,0x10,0xa3,0x6a,0x42,0x86,0x06,0x36,0xc8,0x51,
  0xc7,0x0b,0xc6,0x6a,0x22,0x86,0x22,0x04,0xad,0xa1,0xc4,0x1e,0x45,0xdc,0xa9,0xc9,
  0x19,0x27,0xd0,0xc0,0xc7,0x29,0x50,0x88,0x60,0x04,0x22,0x56,0x8c,0x10,0xc4,0x23,
  0x98,0x0c,0x01,0xc2,0x14,0x50,0x1d,0xf2,0x42,0x11,0x4b,0xdc,0x1a,0x91,0x2f,0x03,
  0xcd,0x56,0xcb,0x11,0x07,0xe1,0x92,0x11,0xa2,0x1a,0xf9,0xf2,0x82,0xc5,0xd7,0x0d,
  0x04,0x49,0x18,0x90,0xf6,0x2c,0xf4,0xd0,0x44,0x17,0x6d,0xf4,0xd1,0x48,0x27,0xad,
  0xf4,0xd2,0x4c,0x37,0xed,0xf4,0xd3,0x27,0x05,0x04,0x00,0x3b
  };

class Keypad : public FXMainWindow, public Bayonne
{
	FXDECLARE(Keypad)
protected:
	FXTextField *display, *lnum, *command, *output[6];
	FXStatusBar *status;
	FXFont *font;
	FXButton *digit[12];
	FXButton *control[5];
	Line *last;
	bool active;

public:
	long onDigit(FXObject *,FXSelector,void*);
	long onRing(FXObject *, FXSelector, void *);
	long onWink(FXObject *, FXSelector, void *);
        long onStop(FXObject *, FXSelector, void *); 
        long onDrop(FXObject *, FXSelector, void *); 
        long onDown(FXObject *, FXSelector, void *); 
	void onUpdate(void);
	void onEcho(void);

	Keypad() {};

	enum {
		ID_TEXT = FXMainWindow::ID_LAST,
		ID_0,
		ID_1,
		ID_2,
		ID_3,
		ID_4,
		ID_5,
		ID_6,
		ID_7,
		ID_8,
		ID_9,
		ID_STAR,
		ID_POUND,
		ID_RING,
		ID_WINK,
		ID_STOP,
		ID_DROP,
		ID_DOWN,
		ID_COMMAND,
		ID_LINE,
		ID_IDLE,
		ID_TIMEOUT
	};
public:
	Keypad(FXApp *a);
	virtual ~Keypad();

	virtual FXbool close(FXbool notify = FALSE);

	virtual void create();
};

class Methods : public BayonneSession
{
public:
	bool scrEcho(void);
};

static Bayonne::timeslot_t ts;
static BayonneSession *session = NULL;
static Keypad *keypad = NULL;
static volatile bool up = false;
static Script::Method echo;
static unsigned echoseq = 0;
static unsigned echoline = 0;
static char echotext[5][21];

static Script::Define plugin[] = {
	{"echo", false, (Script::Method)&Methods::scrEcho,
		(Script::Check)&ScriptChecks::chkHasArgs},
	{NULL, false, NULL, NULL}};

Desktop::Desktop(timeslot_t t) :
Thread(0), ScriptBinder()
{
	echo = Bayonne::server->getHandler("echo");
	ts = t;
	bind(plugin);
}

void Desktop::run(void)
{
	static char *argv[2] = {"bayonne", NULL};
	int argc = 1;
	uint16 lastseq = 0xffff, seq;
	unsigned lastecho = 0xffff;

	session = Bayonne::getSession(ts);

	waitLoaded();

	FXApp app("Bayonne", FXString::null);
	app.init(argc, argv);
	keypad = new Keypad(&app);
#ifndef	WIN32
	app.addSignal(SIGINT,keypad,Keypad::ID_CLOSE);
#endif
	app.addChore(keypad, Keypad::ID_IDLE, NULL);
	up = true;
	new FXToolTip(&app, 0);
	app.create();
	for(;;)
	{
		if(!app.runWhileEvents())
			break;
		seq = session->getEventSequence();
                if(echoseq != lastecho)
                {
                        lastecho = echoseq;
                        keypad->onEcho();       
                } 
		if(seq != lastseq)
		{
			keypad->onUpdate();
			lastseq = seq;
		}
		Thread::yield();
	}
	up = false;
#ifdef	WIN32
	ExitProcess(0);
#else
	raise(SIGTERM);
#endif
	Thread::sync();
}

bool Methods::scrEcho(void)
{
	unsigned i, line = echoline;	
	const char *val;
	unsigned len = 0;

	if(++echoline > 4)
	{
		for(i = 0; i < 3; ++i)
			memcpy(echotext[i], echotext[i + 1], 21);
		--echoline;
	}	

	while(NULL != (val = getValue(NULL)) && len < 20)
	{
		snprintf(echotext[line] + len, 21 - len, "%s", val);
		len = strlen(echotext[line]);
	}
	
	++echoseq;
	frame[stack].index = 0;
	if(echo != NULL)
		return execute(echo);
	advance();
	return true;
}

FXDEFMAP(Keypad) KeypadMap[] = {
	FXMAPFUNCS(SEL_COMMAND,Keypad::ID_0,Keypad::ID_POUND,Keypad::onDigit),
	FXMAPFUNCS(SEL_COMMAND,Keypad::ID_RING,Keypad::ID_RING,Keypad::onRing),
	FXMAPFUNCS(SEL_COMMAND,Keypad::ID_WINK,Keypad::ID_WINK,Keypad::onWink),
        FXMAPFUNCS(SEL_COMMAND,Keypad::ID_STOP,Keypad::ID_STOP,Keypad::onStop), 
        FXMAPFUNCS(SEL_COMMAND,Keypad::ID_DROP,Keypad::ID_DROP,Keypad::onDrop), 
        FXMAPFUNCS(SEL_COMMAND,Keypad::ID_DOWN,Keypad::ID_DOWN,Keypad::onDown)
};

FXIMPLEMENT(Keypad,FXMainWindow,KeypadMap,ARRAYNUMBER(KeypadMap))


Keypad::Keypad(FXApp *a) :
FXMainWindow(a, "Bayonne", NULL, NULL, DECOR_ALL, 0, 0, 0, 0, 0, 0)
{
	FXIcon *icon;
	FXColor digcolor = FXRGB(94, 209, 204);
	FXColor ctrcolor = FXRGB(158,213,188);

	active = true;
	last = NULL;
	font = NULL;

	icon = new FXGIFIcon(getApp(),bayonnelarge);
	setIcon(icon);
	setMiniIcon(icon);
	status = 
		new FXStatusBar(this,LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X|STATUSBAR_WITH_DRAGCORNER|FRAME_RAISED);
	
	FXVerticalFrame *vert =
		new FXVerticalFrame(this, LAYOUT_FILL_X, 0, 0, 0, 0, 8, 8, 8, 4, 1, 1);

	FXHorizontalFrame *displayframe = 
		new FXHorizontalFrame(vert, LAYOUT_FILL_X, 0, 0, 0, 0, 0, 0, 0, 0);

	display = 
		new FXTextField(displayframe, 49, this, ID_TEXT, 
			TEXTFIELD_READONLY|FRAME_SUNKEN|FRAME_THICK|JUSTIFY_LEFT|LAYOUT_FILL_X|LAYOUT_FILL_Y, 0, 0, 0, 0, 4, 4, 1, 1);

	FXHorizontalFrame *buttons = 
new FXHorizontalFrame(this, JUSTIFY_LEFT|LAYOUT_FILL_X|LAYOUT_FILL_Y|PACK_UNIFORM_WIDTH,
 0, 0, 0, 0, 4, 4, 4, 4, 0, 0);

	FXMatrix *keys = 
new FXMatrix(buttons, 4, 
MATRIX_BY_ROWS|LAYOUT_FILL_Y|LAYOUT_FILL_X|
PACK_UNIFORM_WIDTH|PACK_UNIFORM_HEIGHT);

	digit[1] = new FXButton(keys, "1", NULL, this, ID_1,
BUTTON_NORMAL|LAYOUT_FILL_COLUMN|LAYOUT_FILL_ROW|LAYOUT_FILL_X|LAYOUT_FILL_Y,
0, 0, 0, 0, 1, 1, 2, 2);

        digit[4] = new FXButton(keys, "4", NULL, this, ID_4,         
BUTTON_NORMAL|LAYOUT_FILL_COLUMN|LAYOUT_FILL_ROW|LAYOUT_FILL_X|LAYOUT_FILL_Y,   
0, 0, 0, 0, 1, 1, 2, 2);  

        digit[7] = new FXButton(keys, "7", NULL, this, ID_7,         
BUTTON_NORMAL|LAYOUT_FILL_COLUMN|LAYOUT_FILL_ROW|LAYOUT_FILL_X|LAYOUT_FILL_Y,
   0, 0, 0, 0, 1, 1, 2, 2);  

        digit[10] = new FXButton(keys, "*", NULL, this, ID_STAR,         
BUTTON_NORMAL|LAYOUT_FILL_COLUMN|LAYOUT_FILL_ROW|LAYOUT_FILL_X|LAYOUT_FILL_Y, 
  0, 0, 0, 0, 1, 1, 2, 2); 

        digit[2] = new FXButton(keys, "2", NULL, this, ID_2,
BUTTON_NORMAL|LAYOUT_FILL_COLUMN|LAYOUT_FILL_ROW|LAYOUT_FILL_X|LAYOUT_FILL_Y,
0, 0, 0, 0, 1, 1, 2, 2);

        digit[5] = new FXButton(keys, "5", NULL, this, ID_5,
BUTTON_NORMAL|LAYOUT_FILL_COLUMN|LAYOUT_FILL_ROW|LAYOUT_FILL_X|LAYOUT_FILL_Y,
0, 0, 0, 0, 1, 1, 2, 2);

        digit[8] = new FXButton(keys, "8", NULL, this, ID_8,
BUTTON_NORMAL|LAYOUT_FILL_COLUMN|LAYOUT_FILL_ROW|LAYOUT_FILL_X|LAYOUT_FILL_Y,
   0, 0, 0, 0, 1, 1, 2, 2);

        digit[0] = new FXButton(keys, "0", NULL, this, ID_0,
BUTTON_NORMAL|LAYOUT_FILL_COLUMN|LAYOUT_FILL_ROW|LAYOUT_FILL_X|LAYOUT_FILL_Y, 
0, 0, 0, 0, 1, 1, 2, 2); 

        digit[3] = new FXButton(keys, "3", NULL, this, ID_3,
BUTTON_NORMAL|LAYOUT_FILL_COLUMN|LAYOUT_FILL_ROW|LAYOUT_FILL_X|LAYOUT_FILL_Y,
0, 0, 0, 0, 1, 1, 2, 2);

        digit[6] = new FXButton(keys, "6", NULL, this, ID_6,
BUTTON_NORMAL|LAYOUT_FILL_COLUMN|LAYOUT_FILL_ROW|LAYOUT_FILL_X|LAYOUT_FILL_Y,
0, 0, 0, 0, 1, 1, 2, 2);

        digit[9] = new FXButton(keys, "9", NULL, this, ID_9,
BUTTON_NORMAL|LAYOUT_FILL_COLUMN|LAYOUT_FILL_ROW|LAYOUT_FILL_X|LAYOUT_FILL_Y,
   0, 0, 0, 0, 1, 1, 2, 2);

        digit[11] = new FXButton(keys, "#", NULL, this, ID_POUND,
BUTTON_NORMAL|LAYOUT_FILL_COLUMN|LAYOUT_FILL_ROW|LAYOUT_FILL_X|LAYOUT_FILL_Y,
     0, 0, 0, 0, 1, 1, 2, 2); 

        FXMatrix *ctrls =
new FXMatrix(buttons, 5,
MATRIX_BY_ROWS|LAYOUT_FILL_Y|
PACK_UNIFORM_WIDTH|PACK_UNIFORM_HEIGHT); 

	control[0] = new FXButton(ctrls, "ring", NULL, this, ID_RING,
		FRAME_RAISED|LAYOUT_FILL_X|LAYOUT_FILL_Y);

        control[1] = new FXButton(ctrls, "wink", NULL, this, ID_WINK,
                FRAME_RAISED|LAYOUT_FILL_X|LAYOUT_FILL_Y);    

        control[2] = new FXButton(ctrls, "stop", NULL, this, ID_STOP,
                FRAME_RAISED|LAYOUT_FILL_X|LAYOUT_FILL_Y);   

        control[3] = new FXButton(ctrls, "drop", NULL, this, ID_DROP,
                FRAME_RAISED|LAYOUT_FILL_X|LAYOUT_FILL_Y);   

        control[4] = new FXButton(ctrls, "down", NULL, this, ID_DOWN,
                FRAME_RAISED|LAYOUT_FILL_X|LAYOUT_FILL_Y);   

        FXVerticalFrame *text =
		new FXVerticalFrame(buttons, 
	JUSTIFY_LEFT|LAYOUT_FILL_X|LAYOUT_FILL_Y|FRAME_SUNKEN|FRAME_THICK|LAYOUT_LEFT);
	
	output[0] = new FXTextField(text, 0, this, ID_COMMAND,
		TEXTFIELD_READONLY|LAYOUT_LEFT|LAYOUT_FILL_X|LAYOUT_FILL_Y);
	output[0]->setBackColor(getBackColor());
	output[0]->setText("12345678901234567890");

        output[1] = new FXTextField(text, 0, this, ID_COMMAND,
                TEXTFIELD_READONLY|LAYOUT_LEFT|LAYOUT_FILL_X|LAYOUT_FILL_Y);
        output[1]->setBackColor(getBackColor());
        output[1]->setText("ABLE");   

        output[2] = new FXTextField(text, 0, this, ID_COMMAND,
                TEXTFIELD_READONLY|LAYOUT_LEFT|LAYOUT_FILL_X|LAYOUT_FILL_Y);
        output[2]->setBackColor(getBackColor());
        output[2]->setText("ABLE");   

        output[3] = new FXTextField(text, 0, this, ID_COMMAND,
                TEXTFIELD_READONLY|LAYOUT_LEFT|LAYOUT_FILL_X|LAYOUT_FILL_Y);
        output[3]->setBackColor(getBackColor());
        output[3]->setText("ABLE");

        output[4] = new FXTextField(text, 0, this, ID_COMMAND,
                TEXTFIELD_READONLY|LAYOUT_LEFT|LAYOUT_FILL_X|LAYOUT_FILL_Y);
        output[4]->setBackColor(getBackColor());
        output[4]->setText("ABLE");

	command = new FXTextField(status, 8, this, ID_COMMAND, 
		FRAME_SUNKEN|JUSTIFY_RIGHT|LAYOUT_RIGHT|LAYOUT_CENTER_Y,0,0,0,0,2,2,1,1); 
	command->setBackColor(status->getBackColor());
        new FXLabel(status, " Cmd:", NULL, LAYOUT_RIGHT|LAYOUT_CENTER_Y);   

	lnum = new FXTextField(status, 4, this, ID_LINE,
		FRAME_SUNKEN|JUSTIFY_RIGHT|LAYOUT_RIGHT|LAYOUT_CENTER_Y,0,0,0,0,2,2,1,1);
        lnum->setBackColor(status->getBackColor());  		
        new FXLabel(status, " Line:", NULL, LAYOUT_RIGHT|LAYOUT_CENTER_Y); 
                                            
        digit[0]->addHotKey(MKUINT(KEY_0, 0));
        digit[0]->addHotKey(MKUINT(KEY_KP_0, 0)); 
	digit[1]->addHotKey(MKUINT(KEY_1, 0));
	digit[1]->addHotKey(MKUINT(KEY_KP_1, 0));
        digit[2]->addHotKey(MKUINT(KEY_2, 0));
        digit[2]->addHotKey(MKUINT(KEY_KP_2, 0)); 
        digit[3]->addHotKey(MKUINT(KEY_3, 0));
        digit[3]->addHotKey(MKUINT(KEY_KP_3, 0)); 
	digit[4]->addHotKey(MKUINT(KEY_4, 0));
	digit[4]->addHotKey(MKUINT(KEY_KP_4, 0));
        digit[5]->addHotKey(MKUINT(KEY_5, 0));
        digit[5]->addHotKey(MKUINT(KEY_KP_5, 0)); 
        digit[6]->addHotKey(MKUINT(KEY_6, 0));
        digit[6]->addHotKey(MKUINT(KEY_KP_6, 0)); 
        digit[7]->addHotKey(MKUINT(KEY_7, 0));
        digit[7]->addHotKey(MKUINT(KEY_KP_7, 0)); 
        digit[8]->addHotKey(MKUINT(KEY_8, 0));
        digit[8]->addHotKey(MKUINT(KEY_KP_8, 0));
        digit[9]->addHotKey(MKUINT(KEY_9, 0));
        digit[9]->addHotKey(MKUINT(KEY_KP_9, 0));  	
	digit[10]->addHotKey(MKUINT(KEY_asterisk,SHIFTMASK));
	digit[10]->addHotKey(MKUINT(KEY_KP_Multiply,0));
	digit[11]->addHotKey(MKUINT(KEY_Return, 0));
	digit[11]->addHotKey(MKUINT(KEY_numbersign,SHIFTMASK));

  getAccelTable()->addAccel(MKUINT(KEY_Q,0),this,FXSEL(SEL_COMMAND,ID_CLOSE));
  getAccelTable()->addAccel(MKUINT(KEY_q,0),this,FXSEL(SEL_COMMAND,ID_CLOSE)); 
  getAccelTable()->addAccel(MKUINT(KEY_q,CONTROLMASK),this,FXSEL(SEL_COMMAND,ID_CLOSE));   
  getAccelTable()->addAccel(MKUINT(KEY_Escape,0),this,FXSEL(SEL_COMMAND, ID_CLOSE)); 

	FXColor hilite = makeHiliteColor(digcolor);
	FXColor shadow = makeShadowColor(digcolor);
	FXuint i = 0;
	for(i = 0; i < 12; i++)
	{
		digit[i]->setBackColor(digcolor);
		digit[i]->setHiliteColor(hilite);
		digit[i]->setShadowColor(shadow);
	}
	hilite = makeHiliteColor(ctrcolor);
	shadow = makeShadowColor(ctrcolor);
	for(i = 0; i < 5; i++)
	{		
		control[i]->setBackColor(ctrcolor);
		control[i]->setHiliteColor(hilite);
		control[i]->setShadowColor(shadow);
	}
}

void Keypad::onEcho(void)
{
	int i;
	for(i = 0; i < 5; ++i)
		output[i]->setText(echotext[i]);
}		

void Keypad::onUpdate(void)
{
	FXStatusLine *sl = status->getStatusLine();
	session->enter();
	int i;

	Line *line = session->getLine();
	Name *scr = session->getName();

	const char *cp = session->getSymbol("session.digits");
	if(!session->getImage())
		cp = NULL;

	if(cp)
	{
		char ln[6];
		Line *line = session->getLine();
		sl->setText(scr->name);
		sl->setNormalText(scr->name);
		if(line && line->cmd)
		{
			command->setText(line->cmd);
			snprintf(ln, sizeof(ln), "%d", line->lnum);
			lnum->setText(ln);
		}
		else
		{
			command->setText("eof");
			lnum->setText("-");
		}


		if(!active)
		{	
			echoline = 0;
			active = true;	
			control[0]->disable();
			control[1]->enable();
			control[2]->enable();
			control[3]->enable();
			for(i = 0; i < 5; ++i)
				output[i]->setText("");
		}
		last = line;
		display->setText(cp);
	}
	else if(active)
	{
		last = NULL;
		active = false;
		control[0]->enable();
                control[1]->disable();
                control[2]->disable(); 
                control[3]->disable(); 
		sl->setNormalText("Ready.");
		sl->setText("-idle-");
		sl->update();
		display->setText("");
		lnum->setText(" ");
		command->setText(" ");
	}
	session->leave();
}

long Keypad::onDown(FXObject *sender, FXSelector sel, void *)
{
#ifdef	WIN32
	ExitProcess(0);
#else
	keypad->close();
#endif
	return 1;
}

long Keypad::onStop(FXObject *sender, FXSelector sel, void *p)
{
        Event event;

        memset(&event, 0, sizeof(event));

        event.id = STOP_SCRIPT;
        session->queEvent(&event);
	return 1;
}

long Keypad::onDrop(FXObject *sender, FXSelector sel, void *p)
{
        Event event;

        memset(&event, 0, sizeof(event));

        event.id = LINE_DISCONNECT;
        session->queEvent(&event);
	return 1;
}

long Keypad::onWink(FXObject *sender, FXSelector sel, void *p)
{
	Event event;

	memset(&event, 0, sizeof(event));

	event.id = LINE_WINK;
	session->queEvent(&event);
	return 1;
}		

long Keypad::onRing(FXObject *sender, FXSelector sel, void *p)
{
	Event event;
	
	if(session->isIdle())
	{
		memset(&event, 0, sizeof(event));
		event.id = RING_ON;
		session->queEvent(&event);
		Thread::sleep(100);
		event.id = RING_OFF;
		session->queEvent(&event);	
	}	
	return 1;
}

long Keypad::onDigit(FXObject *sender, FXSelector sel, void *p)
{
	Event event;

	memset(&event, 0, sizeof(event));
	event.id = DTMF_KEYUP;
	event.dtmf.duration = 60;
	event.dtmf.digit = FXSELID(sel) - ID_0;
	session->queEvent(&event);
	return 1;
}

void Keypad::create()
{
	FXMainWindow::create();
	show();
}

FXbool Keypad::close(FXbool notify)
{
	return FXMainWindow::close(notify);
}

Keypad::~Keypad()
{
}

} // namespace

#endif
