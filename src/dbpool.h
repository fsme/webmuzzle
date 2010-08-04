//@(#) Pool of connection to database 
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#ifndef	WEBMUZZLE_DBPOOL_H
#define	WEBMUZZLE_DBPOOL_H

#ifndef MAX_DB_CONNECT 
#define MAX_DB_CONNECT 512
#endif

#include <string>
#include <map>
#include <stdexcept>

#include "fsm_state.h"
#include "state_logout.h"

using namespace std;

namespace webmuzzle {

///\brief Static pool of connection
class dbpool
{
private:
static map< string, fsm_state* > FSMpool;

public:
///\brief Destroy : cleanup pool of connection
~dbpool ()
{
	map< string, fsm_state* >::iterator it = FSMpool.begin();
	for(; it != FSMpool.end(); ++it)
		delete FSMpool [ it->first ];
}

///\brief Select exist or create connection for session
fsm_state* get_connect (
	  const string& sid_ ///\param sid Session ID
	, auto_ptr<request_data> data_ ///\param data_ Request Data
) {
	if ( FSMpool.size() > MAX_DB_CONNECT ) {
		; //!!!!! Find and erase a junk
	}

	if ( FSMpool.find(sid_) == FSMpool.end())
		FSMpool [sid_] = new state::logout (data_);

	return FSMpool [sid_];
}

///\brief Set new FSM state
fsm_state* next_state_is (
	  const string& sid_///\param sid_ Session ID
	, webmuzzle::fsm_state* next_///\param next_ New state for FSM
) {
	if ( FSMpool.find(sid_) == FSMpool.end())
	throw domain_error (\
				next_->state_name()+" state for nonexistent session "+sid_);

	delete FSMpool[sid_]; //Free old state : *MUST* be allocated
	return FSMpool[sid_] = next_;
}

}; //dbpool

///\brief Pool's singleton
struct db {
	static dbpool& pool () {
		static dbpool instance;
		return instance;
	}
};

}//::webmuzzle

#endif //WEBMUZZLE_DBPOOL_H
