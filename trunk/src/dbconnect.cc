//@(#) Pool of database connection
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "dbconnect.h"

namespace webmuzzle {

//
void dbconnect::open (
	  apr_pool_t* pool
	, const string& driver_
	, const string& user_
	, const string& passwd_
	, const string& host_
	, const string& port_
	, const string& path_ 
) {
	Status = ::apr_dbd_get_driver (pool, driver_.c_str(), &Driver);
	if ( Status != APR_SUCCESS )
		throw runtime_error ( status());

	Status = ::apr_dbd_open ( Driver, pool
			, dsn [driver_](user_, passwd_, host_, port_, path_).c_str()
			, &Handler );
	if ( !is_open())
		throw runtime_error ( status());
}

//
void dbconnect::close ()
{
	if ( is_open()) ::apr_dbd_close ( Driver, Handler);
	Status = APR_EINIT;
	Driver = 0;
	Handler = 0;
	Last = ::apr_time_now();
}

//
int dbconnect::query (
	  const string& sql
) const {
	int affected, res;
	res = ::apr_dbd_query ( Driver, Handler, &affected, sql.c_str());
	if (0 != res)
		; //!!! exception
	return affected;
}

}//::webmuzzle
