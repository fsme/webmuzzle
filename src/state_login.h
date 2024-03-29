//@(#) States login and logout
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#ifndef	WEBMUZZLE_STATE_LOGIN_H
#define	WEBMUZZLE_STATE_LOGIN_H

#include "fsm_state.h"
#include "state_logout.h"
#include "events.h"

using namespace webmuzzle;
using namespace event;
using namespace std;

namespace state {

///\brief State login
class login
	: public webmuzzle::fsm_state
{
public:

///\brief Create
login ( auto_ptr<request_data> data_///\param data_
);

///\brief Destroy
virtual ~login () {}

///\brief Plug : is done
virtual void do_login ();

///\brief First processing
virtual void do_http_request ();

///\brief Plug
virtual void do_login_failure ();

///\brief Event logout
virtual void do_logout ();

///\brief Name of state (for debug)
virtual const string& state_name () const;

};//state_login

}//::state

#endif //WEBMUZZLE_STATE_LOGIN_H
