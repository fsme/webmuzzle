//@(#) Data block for HTTP-request processing
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#ifndef	WEBMUZZLE_REQUEST_DATA_H
#define	WEBMUZZLE_REQUEST_DATA_H 1

#include "httpd.h"

#include "cookie.h"
#include "client_block.h"
#include "html.h"

namespace webmuzzle {

///\brief Data block for HTTP-request processing
struct request_data
{
request_rec*	APRreq;
client_block	ClientBlock;
cookie			Cookie;
html			Html;

///\brief Create empty by default
request_data () {}

///\brief Create with APR request_rec pointer
request_data (
	  request_rec *req_///\param req_ APR request
)
: APRreq (req_)
, Cookie (req_)
, ClientBlock (req_)
{}

};//request_data 

}//::webmuzzle

#endif //!WEBMUZZLE_REQUEST_DATA_H
