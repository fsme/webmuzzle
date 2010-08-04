//@(#) Webmuzzle's Request processing
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "request.h"

namespace webmuzzle {

//
request::request ( request_rec* req_ ) {
	Data = auto_ptr<request_data>( new request_data (req_));
}

//
void request::fsm_stack (
	  int depth_///\param depth_ Depth of recursive
) {
	try {
		if (0 < depth_) fsm_stack (--depth_);
		FSM->do_http_request();
	} catch (const event::done& e) { throw e;
	} catch (const event::logout& e) { FSM->do_logout();
	} catch (const event::login& e)  { FSM->do_login();
	} catch (const event::login_fail& e) { FSM->do_login_failure();
	} catch (const event::next_state& s) {
			FSM = db::pool().next_state_is ( *session_id.get(), s.new_state());
			if ( s.is_done()) throw event::done();
	}
}

//
void request::processing()
{
	session_id = auto_ptr<string> (new string (Data->Cookie["SID"]));
	session_id->append(Data->APRreq->connection->remote_ip);

	Data->ClientBlock.parse();
	FSM = db::pool().get_connect( *session_id.get(), Data );
	try {
		fsm_stack (3);
	} catch (const event::done& e) { /* OK */ }

	FSM->do_http_response();
}

}//::webmuzzle
