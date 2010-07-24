//@(#) Cookie parse and get (header)
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#ifndef	WEBMUZZLE_REQUEST_H
#define	WEBMUZZLE_REQUEST_H

#include <iostream>

#include "http_protocol.h"

#include "cookie.h"
#include "dbpool.h"
#include "html.h"
#include "client_block.h"

using namespace std;

namespace webmuzzle {

///\brief Class for request processing
///\class request
class request
{
private:
	request_rec* Req;
	cookie Cookie;
	dbconnect dbh;
	client_block Data;
	html Html;

///\brief Check out log in
bool check_login ();

///\brief Flush output response
void response ();


public:

///\brief Create
request (
	  request_rec* req ///\param r APR request pointer
)
: Req(req)
, Cookie(req)
, Data(req)
{
}

///\brief Destroy
~request ()
{
	dbh.last ( ::apr_time_now());
	response();
}

///\brief Make all
void processing ();

}; //request

}//::webmuzzle

#endif //WEBMUZZLE_REQUEST_H
