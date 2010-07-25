//@(#) Cookie parse and get (header)
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#ifndef	WEBMUZZLE_REQUEST_H
#define	WEBMUZZLE_REQUEST_H

#include "http_protocol.h"

#include "dbpool.h"
#include "request_data.h"
#include "fsm.h"

using namespace std;

namespace webmuzzle {

///\brief Class for request processing
///\class request
class request
{
private:
	dbconnect dbh;
	auto_ptr<request_data> Data;

///\brief Flush output response
void response ();

public:

///\brief Create
request (
	  request_rec* req ///\param r APR request pointer
) {
	Data = auto_ptr<request_data>( new request_data (req));
}

///\brief Destroy
~request ()
{
	dbh.last ( ::apr_time_now());
	dbh.FSM()->response();
}

///\brief Make all
void processing ();

}; //request

}//::webmuzzle

#endif //WEBMUZZLE_REQUEST_H
