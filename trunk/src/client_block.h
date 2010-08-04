//@(#) Read client POST and GET data chunks
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#ifndef	WEBMUZZLE_CLIENT_BLOCK_H
#define	WEBMUZZLE_CLIENT_BLOCK_H

#include <string>
#include <map>

#include "http_protocol.h"

#include "namecall.h"

using namespace std;

namespace webmuzzle {

class client_block
{
private:
	request_rec	*Req;
	map< string, string > DataMap;

	char Buf [HUGE_STRING_LEN];
	long Length;

///\brief Parse HTTP input data key1=value1&key2=value2 ...
void parse_data ();

///\brief Parse GET data
void parse_get_data () {}

///\brief Parse POST data
void parse_post_data ();

public:

///\brief Create empty by default
client_block () {}

///\brief Read and parse client data : call named function by HTTP-method
client_block (
	  request_rec *req_///\param req_ APR request pointer
)
: DataMap()
, Req(req_)
{}

///\brief Call function by HTTP-method
void parse ()
{
	if (string("POST") == Req->method ) parse_post_data();
	else
		if (string("GET") == Req->method ) parse_get_data();
}

///\brief Cleanup
void clear () { DataMap.clear(); }

///\brief Try to get data chunk by name
///\return Content of named data
const string& operator[] (
	  const string& key_///param key_ Name of chunk
) {

///	if ( DataMap.find (key_) == DataMap.end())
///	throw out_of_range (key_+": not found into client block");

	return DataMap [key_];
}

};//client_block

}//::webmuzzle

#endif //WEBMUZZLE_CLIENT_BLOCK_H
