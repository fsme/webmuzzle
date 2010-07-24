//@(#) DSN function's map initialization
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "dsn.h"

namespace webmuzzle {

cxx::namecall< string, dsn_func_t > dsn =
	cxx::namecall< string, dsn_func_t >\
\
("mysql", &mysql_magic)\
("pgsql", &pgsql_magic);

}//::webmuzzle
