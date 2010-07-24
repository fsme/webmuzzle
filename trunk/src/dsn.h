//@(#) Virtual base for Data Source Name (DSN)
//Author: Andrew Wingorodov <mail@andr.mobi>
//$Id$

#ifndef	WEBMUZZLE_DSN_H
#define	WEBMUZZLE_DSN_H

#include <string>

#include "namecall.h"

using namespace std;

namespace webmuzzle {

typedef const string&(*dsn_func_t)(\
		  const string&
		, const string&
		, const string&
		, const string&
		, const string&);

///\brief Magic string for MySQL
static
const string& mysql_magic (
	  const string& user_///\param  user_ Database's login user
	, const string& pass_///\param  pass_ Database's login user
	, const string& host_="localhost" ///\param host_ Database's host 
	, const string& port_= "" ///\param port_ Port (if 0 use default)
	, const string& path_="" ///\param path_ Path to socket 
) {
static string magic;
magic = "host=" + host_
		+ ",port=" + ( (port_.size() == 0) ? "3306" : port_ )
		+ ",user=" + user_
		+ ",pass=" + pass_;
	return magic;
}

///\brief Magic string for PostgreSQL
static
const string& pgsql_magic (
	  const string& user_///\param  user_ Database's login user
	, const string& pass_///\param  pass_ Database's login user
	, const string& host_="localhost" ///\param host_ Database's host 
	, const string& port_= "" ///\param port_ Port (if 0 use default)
	, const string& path_="" ///\param path_ Path to socket 
) {
static string magic;
	magic = "pgsql";
	return magic;
}

extern
cxx::namecall< string, dsn_func_t > dsn;

}//::webmuzzle

#endif //WEBMUZZLE_DSN_H
