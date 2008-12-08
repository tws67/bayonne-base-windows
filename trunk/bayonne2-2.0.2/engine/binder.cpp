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

#include "engine.h"

using namespace ost;
using namespace std;

BayonneBinder *BayonneBinder::binder = NULL;

BayonneBinder::BayonneBinder(const char *id) :
ScriptBinder(id)
{
	if(!binder)
		binder = this;
}

BayonneSession *BayonneBinder::session(ScriptInterp *s)
{
	return (BayonneSession *)(s);
}

const char *BayonneBinder::submit(const char **args)
{
	return NULL;
}

void BayonneBinder::report(Call *call)
{
	delete call;
}

ScriptCompiler *BayonneBinder::compiler(void)
{
	ScriptCompiler *img = new ScriptCompiler(server, "/bayonne/server/config");
	if(getUserdata())
		img->loadPrefix("config", "~bayonne/config");

	return img;
}

bool BayonneBinder::scriptEvent(ScriptInterp *interp, const char *evt)
{
	return (session(interp))->stringEvent(evt);
}

bool BayonneBinder::digitEvent(ScriptInterp *interp, const char *evt)
{
	return (session(interp))->digitEvent(evt);
}

ScriptCompiler *BayonneBinder::getCompiler(void)
{
	return binder->compiler();
}

const char *BayonneBinder::submitRequest(const char **args)
{
	return binder->submit(args);
}

void BayonneBinder::reportCall(Call *call)
{
	return binder->report(call);
}	
