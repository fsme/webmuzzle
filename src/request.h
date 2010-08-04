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
#include "events.h"

using namespace std;

namespace webmuzzle {

///\brief Class for request processing
///\class request
class request
{
private:
	fsm_state* FSM;
	auto_ptr<request_data> Data;
	auto_ptr<string> session_id;

///\brief Recursive stack of FSM
void fsm_stack (int depth_///\param depth_ Depth of recursive call
);

public:

///\brief Create
request ( request_rec* req_///\param req_ APR request
);

///\brief Destroy
~request () {}

///\brief Make all
void processing ();

}; //request

}//::webmuzzle

#endif //WEBMUZZLE_REQUEST_H
