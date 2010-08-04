//@(#) State login of webmuzzle
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "state_login.h"

namespace state {

//
login::login ( auto_ptr<request_data> data_) { Data = data_; }

//
void login::do_login () { throw event::done(); }

//
void login::do_login_failure () { throw event::done(); }

//
const string& login::state_name () const
{	static string nm("Login");
	return nm;
}

//
void login::do_http_request ()
{
if (0 == string("/logout").compare(0, sizeof("/logout"), Data->APRreq->uri)
)
 throw event::logout();

	Data->Html.replace("<h1>INSIDE</h1>", "MAINTABLE");
	throw event::done();
}

//
void login::do_logout ()
{
	Data->DB.close();
	Data->Html.loginform (true);
	Data->Html.replace(" Good bye ", "MESSAGE");
	throw event::next_state ( new state::logout(Data));
}

}//::state
