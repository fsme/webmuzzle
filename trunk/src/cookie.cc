//@(#) Webmuzzle's cookie
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "cookie.h"

namespace webmuzzle {

//
const string& cookie::sidgen () const
{
static string hash;
static unsigned char data [RAND_SIZE];
static unsigned char digest [APR_MD5_DIGESTSIZE];

	::apr_generate_random_bytes (data, sizeof(data));
	::apr_md5 (digest, data, sizeof(data));

	hash.clear();
	char c;
	// Convert hex digest to alphabetical string
	for(apr_size_t i = 0; i < APR_MD5_DIGESTSIZE; ++i)
	{
		c = digest[i] & 0x0f; c += (c > 9) ? '7' : '0';
		hash.push_back(c);

		c = digest[i] >> 4; c += (c > 9) ? '7' : '0';
		hash.push_back(c);
	}

	return hash;
}

//
cookie::cookie (
	  request_rec* r
) {
	const char* cookie_in = ::apr_table_get(r->headers_in, "Cookie");
	CookieMap.clear();
	if (!cookie_in) {
		CookieMap["SID"] = sidgen();
		return;
	}

	string Cookies (cookie_in);
	string::size_type posn, pos1, pos2;
	int i = 0;
	while ( (posn = Cookies.find("=")) != string::npos
	) {
		pos1 = 0;
		while ( !isalpha( Cookies[pos1] ) && pos1 != string::npos)
			++pos1;

		if (pos1 == string::npos) break;

		pos2 = Cookies.find(";");
		CookieMap [ Cookies.substr(pos1,posn-pos1) ] = \
							 Cookies.substr (posn+1, pos2-posn-1);

		if (pos2 == string::npos) break;

		Cookies.erase(0, pos2+2);
	}

	if (CookieMap["SID"].size() != 32
	||	CookieMap["SID"].find_first_not_of("0123456789ABCDEF")!= string::npos
	)
	  CookieMap["SID"] = sidgen();
}

//
void cookie::output (
	  request_rec *req
) const {
map<string,string>::const_iterator cook = CookieMap.begin();

	const char* buf;
	for (; cook != CookieMap.end(); ++cook)
	{
		buf = ::apr_psprintf ( req->pool , "%s=%s;"
					, cook->first.c_str(), cook->second.c_str()
				);
		if (buf) ::apr_table_addn ( req->headers_out, "Set-Cookie", buf);
	}
}

}//::webmuzzle
