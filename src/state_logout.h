//@(#) States login and logout
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#ifndef	WEBMUZZLE_STATE_LOGOUT_H
#define	WEBMUZZLE_STATE_LOGOUT_H

#include "fsm_state.h"
#include "state_login.h"
#include "events.h"

using namespace webmuzzle;
using namespace event;
using namespace std;

namespace state {

///\brief FSM-state Logout
class logout
	: public webmuzzle::fsm_state
{
public:

///\brief Create
logout ( auto_ptr<request_data> data_///\param data_ 
);

///\brief Try to login
///\throw event::next_state OR event::login_fail
virtual void do_login ();

///\brief Logout
virtual void do_logout ();

///\brief First processing
virtual void do_http_request ();

///\brief Login fail
virtual void do_login_failure ();

///\brief Name of state (for debug)
virtual const string& state_name () const;

///\brief Destroy
virtual ~logout () {}

};//logout


}//::state

#endif //! WEBMUZZLE_STATE_LOGOUT_H
