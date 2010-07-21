//@(#) Pool of database connection
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "dbconnect.h"

namespace webmuzzle {

//
void dbconnect::open (
	  apr_pool_t* pool
) {
	Status = ::apr_dbd_get_driver (pool, "mysql", &Driver);
	if ( Status != APR_SUCCESS )
		throw runtime_error ( status());

	Status = ::apr_dbd_open ( Driver, pool
				, "host=localhost,user=test,pass=test", &Handler);
	if ( !is_open())
		throw runtime_error ( status());
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
