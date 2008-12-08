/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "bayonne_rpc.h"
/* Copyright (C) 2005 Open Source Telecom Corporation.
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License version 2 as published by the Free Software Foundation.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 * 
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.                                                 
 */

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

bayonne_error *
bayonne_reload_2(void *argp, CLIENT *clnt)
{
	static bayonne_error clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, BAYONNE_RELOAD,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_bayonne_error, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

bayonne_error *
bayonne_shutdown_2(void *argp, CLIENT *clnt)
{
	static bayonne_error clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, BAYONNE_SHUTDOWN,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_bayonne_error, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

bayonne_status *
bayonne_status_2(void *argp, CLIENT *clnt)
{
	static bayonne_status clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, BAYONNE_STATUS,
		(xdrproc_t) xdr_void, (caddr_t) argp,
		(xdrproc_t) xdr_bayonne_status, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

bayonne_result *
bayonne_start_2(bayonne_start *argp, CLIENT *clnt)
{
	static bayonne_result clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, BAYONNE_START,
		(xdrproc_t) xdr_bayonne_start, (caddr_t) argp,
		(xdrproc_t) xdr_bayonne_result, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

bayonne_error *
bayonne_stop_2(bayonne_session *argp, CLIENT *clnt)
{
	static bayonne_error clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, BAYONNE_STOP,
		(xdrproc_t) xdr_bayonne_session, (caddr_t) argp,
		(xdrproc_t) xdr_bayonne_error, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
