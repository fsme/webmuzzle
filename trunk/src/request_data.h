//@(#) Data block for HTTP-request processing
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#ifndef	WEBMUZZLE_REQUEST_DATA_H
#define	WEBMUZZLE_REQUEST_DATA_H 1

#include "httpd.h"

#include "html.h"
#include "cookie.h"
#include "client_block.h"
#include "dbconnect.h"

namespace webmuzzle {

///\brief Data block for HTTP-request processing
struct request_data
{
request_rec*	APRreq;
html			Html;
cookie			Cookie;
client_block	ClientBlock;
dbconnect		DB;

///\brief Create empty by default
request_data () : APRreq (0) {}

///\brief Create with APR request_rec pointer
request_data (
	  request_rec *req_///\param req_ APR request
)
: APRreq (req_)
, Cookie (req_)
, ClientBlock (req_)
{}

///\brief HTTP-response and cleanup data of client
void http_response () ;

};//request_data 

}//::webmuzzle

#endif //!WEBMUZZLE_REQUEST_DATA_H
