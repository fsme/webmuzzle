//@(#) Cookie parse and get (header)
//Author: Andrew Wingorodov <mail@andr.mobi>
//$Id$

#ifndef	WEBMUZZLE_REQUEST_H
#define	WEBMUZZLE_REQUEST_H

#include <iostream>

#include "http_protocol.h"

#include "cookie.h"
#include "dbpool.h"

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

public:

///\brief Create
request (
	  request_rec* req ///\param r APR request pointer
)
: Req(req)
, Cookie(req)
{}

///\brief Destroy
~request ()
{
	dbh.last ( ::apr_time_now());
	response();
}

///\brief Make all processing
void exec ();

///\brief Flush output response
void response ();

}; //request

}//::webmuzzle

#endif //WEBMUZZLE_REQUEST_H
