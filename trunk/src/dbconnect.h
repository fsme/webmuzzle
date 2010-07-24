//@(#) Pool of connection to database 
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#ifndef	WEBMUZZLE_DBCONNECT_H
#define	WEBMUZZLE_DBCONNECT_H

#include <string>
#include <stdexcept>

#include "apr_dbd.h"
#include "apr_hash.h"
#include "apr_time.h"

#include "dsn.h"

using namespace std;

namespace webmuzzle {

///\brief Static database pool
class dbconnect
{
private:
 	apr_dbd_t*		Handler;
const
apr_dbd_driver_t*		Driver;
	apr_hash_t*		Prepared;
	apr_status_t	Status;
	apr_time_t		Last;
	string		Remote;

public:

///\brief Create
dbconnect ()
: Status(APR_EINIT)
{
	Last = ::apr_time_now();
}

///\brief Destroy
~dbconnect () { this->close(); }

///\brief Close and cleanup connection
void close ()
{
	if ( is_open()) ::apr_dbd_close ( Driver, Handler);
	Status = APR_EINIT;
	Driver = 0;
	Handler = 0;
	Last = ::apr_time_now();
	Remote.clear();
}

///\brief Open connect
void open (
	  apr_pool_t* pool ///\param pool APR pool to register cleanup
	, const string& driver_///\param driver_ Name driver
	, const string& user_///\param user_ Database's user
	, const string& passwd_///\param passwd_ Database's password
	, const string& host_///\param host_ Database's host
	, const string& port_ = "" ///\param port_ Port (0 - use default)
	, const string& path_ = "" ///\param path_ Socket path
);

///\brief Do SQL-request (non-result)
int query (
	  const string& sql ///\param sql SQL query
) const;

///\brief Get status as string
const string& status () const
{
static string msg;

	msg = "<h1>Error</h1>";
	return msg;
}

///\brief Get remote IP
inline const string& remote () const { return Remote; }

///\brief Set remote IP (at first time)
inline const string& remote (
	  const char* rip ///\param rip Remote IP
) {
	return Remote = rip; }

///\brief Get last access time
inline apr_time_t last () const { return Last; }

///\brief Set last access time
inline apr_time_t last (
	  apr_time_t t ///\param t APR time
) {
	return Last = t; }

///\brief Get status
inline bool is_open () const
{
	// apr_dbd_check_conn (...)
	return Status == APR_SUCCESS;
}

}; //dbconnect


}//::webmuzzle

#endif //WEBMUZZLE_DBCONNECT_H
