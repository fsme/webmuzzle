//@(#) Virtual interface for states of FSM logical
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#ifndef	CXX_FSM_STATE_H
#define	CXX_FSM_STATE_H 1

#include <memory>

#include "request_data.h"

using namespace std;

namespace webmuzzle {

class fsm_state
{
protected:
	auto_ptr<request_data>	Data;

public:

///\brief Destroy
virtual ~fsm_state () {}

///\brief Initialization data block
void init (
	  auto_ptr<request_data> data_ptr ///\param data_ptr Prepared request data
) {
	Data = data_ptr;
}

///\brief HTTP-response for result
void response ()
{
	Data->Cookie.output( Data->APRreq);
	::ap_set_content_type (  Data->APRreq, "text/html; charset=UTF-8");
	::ap_set_content_length( Data->APRreq
							, static_cast<apr_off_t>(Data->Html.str().size()));
	::ap_rprintf( Data->APRreq, "%s", Data->Html.str().c_str());
	Data->Cookie.clear();
	Data->Html.clear();
}

///\brief Processing HTTP request
virtual void do_http_request() = 0;

///\brief Event try to login
virtual void do_login () = 0;

///\brief Event dump failure login
virtual void do_login_failure () = 0;

///\brief Event logout
virtual void do_logout () = 0;

};//fsm_state

}//::webmuzzle

#endif //CXX_FSM_STATE_H
