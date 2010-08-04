//@(#) Virtual base for event-exception of FSM logical
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#ifndef	WEBMUZZLE_EVENT_H
#define	WEBMUZZLE_EVENT_H

#include <exception>

#include "fsm_state.h"

using namespace std;
using namespace webmuzzle;

namespace event {

///\brief Interface of event
class base_event
	: public std::exception
{
protected:
	string message;

public:
///\brief Create
explicit base_event ( const string& msg = "") : message (msg) {}

///\brief Destroy
virtual ~base_event () throw () {}

///\brief Get message
virtual const char* what() const throw () { return message.c_str(); }

};//base_event base

///\class next_state
///\brief Special exception for change of state of FSM
class next_state
	: public base_event
{
private:
	fsm_state* State;
	bool Done;

public:

///\brief Create
explicit next_state (
	  fsm_state* new_state ///\param new_state New state for FSM
	, bool is_done_ = false ///\param is_done_ Set True to break processing
)
: base_event ("New state")
, State (new_state)
, Done (is_done_)
{}

///\brief Next state for FSM
fsm_state* new_state () const throw () { return State; }

///\brief Check done flag
inline bool is_done () const throw () { return Done; }

///\brief Destroy virtual throw
virtual ~next_state () throw () {}

};//next_state


///\class logout
///\brief Event logout about 
class logout
	: public base_event
{
public:
explicit logout () : base_event("Logout event") {}

///\brief Destroy virtual throw
virtual ~logout () throw () {}

};//logout


///\brief Event login for
class login
	: public base_event
{
public:
explicit login () : base_event("Login event") {}

///\brief Destroy virtual throw
virtual ~login () throw () {}

};//login


///\brief Event login failure
class login_fail
	: public base_event
{
public:
explicit login_fail () : base_event("Login falure") {}

///\brief Destroy virtual throw
virtual ~login_fail () throw () {}

};//login_fail


///\brief Special exception for break processing
class done
	: public base_event
{
public:
explicit done () : base_event("Break processing") {}

///\brief Destroy virtual throw
virtual ~done () throw () {}

};//is_done

}//::event

#endif //!WEBMUZZLE_EVENT_H
