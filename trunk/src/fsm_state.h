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

///\brief Set request data block
inline
void data (
	  auto_ptr<request_data> data_ptr ///\param data_ptr Prepared request data
) {
	Data = data_ptr;
}

///\brief Tranfer request data for next FSM-state
auto_ptr<request_data> data () { return Data; }

///\brief Set message
void message (
	  const string& msg_///\param msg_
) {
	Data->Html.replace(msg_, "MESSAGE");
}

///\brief Initialization data block
void do_http_response () { Data->http_response(); }

///\brief Processing HTTP request
virtual void do_http_request() = 0;

///\brief Get state name as string
virtual const string& state_name () const = 0;

///\brief Event try to login
virtual void do_login () = 0;

///\brief Event dump failure login
virtual void do_login_failure () = 0;

///\brief Event logout
virtual void do_logout () = 0;

};//fsm_state

}//::webmuzzle

#endif //CXX_FSM_STATE_H
