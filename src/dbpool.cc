//@(#) Pool of database connection
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "dbpool.h"

namespace webmuzzle {

map<string,dbconnect> dbpool::DBPool;
apr_pool_t *dbpool::apr_pool;

}//::webmuzzle
