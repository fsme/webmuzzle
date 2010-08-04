//@(#) State logout
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "state_logout.h"

namespace state {

//
logout::logout (auto_ptr<request_data> data_) { fsm_state::Data = data_; }

//
void logout::do_login ()
{
	try {
		Data->DB.open ( Data->APRreq->pool
				, Data->ClientBlock ["driver"]
				, Data->ClientBlock ["user"]
				, Data->ClientBlock ["password"]
				, Data->ClientBlock ["host"]
				, Data->ClientBlock ["port"]
				, Data->ClientBlock ["path"]
		);
	} catch (const std::exception& e) { /* Log e.what(); */ }

	if ( !Data->DB.is_open()) throw event::login_fail();
	else
		throw event::next_state ( new state::login(Data));
}

//
void logout::do_http_request ()
{
	if (0 < Data->ClientBlock["user"].size()) throw event::login();
	//do_login();
	
	Data->Html.loginform(true);
	Data->Html.replace(" Login please ", "MESSAGE");
	throw event::done();
}

//
void logout::do_login_failure ()
{
	Data->Html.loginform(true);
	Data->Html.replace(" Login failure ", "MESSAGE");
	throw event::done();
}

//
const string& logout::state_name () const
{	static string nm("Logout");
	return nm;
}

//
void logout::do_logout () { throw event::done(); }

}//::state
