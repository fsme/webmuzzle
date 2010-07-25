//@(#) Virtual base for event-exception of FSM logical
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#ifndef	WEBMUZZLE_EVENT_H
#define	WEBMUZZLE_EVENT_H 1

#include <memory>
#include <exception>

#include "fsm_state.h"

using namespace std;

namespace event {

///
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


///class next_state
///brief Special exception for change of state of FSM
class next_state
	: public base_event
{
private:
	auto_ptr<fsm_state> NextState;
	bool Done;

public:

///\brief Create
explicit next_state (
	  auto_ptr<fsm_state> state_ptr ///\param ptr_ New state for FSM
	, bool is_done_ = true ///\param is_done_ Set false for continue processing
)
: base_event ("New state of FSM")
, NextState (state_ptr)
, Done (is_done_)
{}

///\brief Next state for FSM
auto_ptr<fsm_state> next_state_is () throw () { return NextState; }

///\brief Check done flag
inline bool is_done () throw () { return Done; }

///\brief Destroy virtual throw
virtual ~next_state () throw () {}

};//next_state


///class logout
///brief Event logout about 
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
class is_done
	: public base_event
{
public:
explicit is_done () : base_event("Break request processing") {}

///\brief Destroy virtual throw
virtual ~is_done () throw () {}

};//is_done

}//::event

#endif //!WEBMUZZLE_EVENT_H
