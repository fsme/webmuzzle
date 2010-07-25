//@(#) State logout
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#ifndef	WEBMUZZLE_STATE_LOGIN_H
#define	WEBMUZZLE_STATE_LOGIN_H 1

#include "fsm_state.h"

using namespace std;

namespace state {

///\brief
class logout
	: public webmuzzle::fsm_state
{
using webmuzzle::fsm_state::Data;
public:

///\brief Event try to login
virtual void do_login ()
{
///Make login
}

///\brief Event logout
virtual void do_logout () { /* ignore */ }

///\brief 
virtual void do_http_request ()
{
	Data->Html.replace("<h1>Welcome</h1>", "MAINTABLE");
	///throw event::is_done();
}

///\brief 
virtual void do_login_failure () { /* ignore */ }

///\brief Destroy
virtual ~logout () {}

};//logout


///\brief State login
class login
	: public webmuzzle::fsm_state
{
public:

///\brief Event try to login
virtual void do_login ()
{
///Make login
}

///\brief Event logout
virtual void do_logout () { /* ignore */ }

///\brief Destroy
virtual ~login () {}

};//state_login

}//::webmuzzle

#endif //WEBMUZZLE_STATE_LOGIN_H
