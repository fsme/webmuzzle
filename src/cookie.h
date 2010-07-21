//@(#) Cookie parse and get (header)
//Author: Andrew Wingorodov <mail@andr.mobi>
//$Id$

#ifndef	WEBMUZZLE_COOKIE_H
#define	WEBMUZZLE_COOKIE_H

#include <string>
#include <map>

#include "httpd.h"
#include "apr_strings.h"
#include "apr_md5.h"

#ifndef RAND_SIZE
#define RAND_SIZE 256
#endif

using namespace std;

namespace webmuzzle {

///\brief
class cookie
{
private:
	map< string, string > CookieMap;

///\brief SID random generate
const string& sidgen () const;

public:

///\brief Create : read cookie from request headers
cookie (
	  request_rec *r ///\param r APR request
);

///\brief Get or set cookie by name
string& operator[] (const string& key///\param key_ Name of cookie
) {
	return CookieMap [key]; }


///\brief Output cookie to response headers
void output (
	  request_rec *req ///\param req APR request ptr
) const ;

}; //cookie

}//::webmuzzle

#endif //WEBMUZZLE_COOKIE_H
