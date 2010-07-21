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

//#include "apr_dbd.h"

#include "dbconnect.h"

using namespace std;

namespace webmuzzle {

///\brief Static database pool
class dbpool
{
private:
static map< string, dbconnect > DBPool;
static apr_pool_t *apr_pool;

public:

///\brief Keep APR pool : call only once!
void init (
	  apr_pool_t* p ///\param p
) {
	apr_pool = p;
	::apr_dbd_init (apr_pool);
}

///\brief Select exist or create connection for session
dbconnect& open (
	  const string& SID ///\param sid Session ID
	, const char* rip ///\param rip Remote IP
) {
	if ( DBPool.size() > MAX_DB_CONNECT ) {
		; //!!!!! Drop olderst
	}

	if ( DBPool.find(SID) == DBPool.end()) { DBPool [SID].remote(rip); }

	if ( DBPool [SID].remote() != rip )
		throw domain_error (SID + " mismatch remote IP " + rip);

	return DBPool [SID];
}

}; //dbpool

///\brief Pool singleton
struct dbase {
	static dbpool& pool () {
		static dbpool instance;
		return instance;
	}
};

}//::webmuzzle

#endif //WEBMUZZLE_DBPOOL_H
