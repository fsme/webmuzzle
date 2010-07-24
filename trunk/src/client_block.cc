//@(#) Read client POST and GET data chunks (code)
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "client_block.h"

namespace webmuzzle {

//
void client_block::parse_data ()
{
const char *data, *key, *value;
data = Buf;

	while (*data && (value = ::ap_getword (Req->pool, &data, '&')))
	{
		key = ::ap_getword (Req->pool, &value, '=');
		::ap_unescape_url( (char*) key);
		::ap_unescape_url( (char*) value);
		DataMap [key] = value;
	}
}

//
void client_block::parse_post_data (
) {
	if ( (OK != ::ap_setup_client_block (Req, REQUEST_CHUNKED_ERROR))
	|| !::ap_should_client_block(Req))
		return;
	
	while (0 < (Length = ::ap_get_client_block(Req, Buf, sizeof(Buf))) )
		this->parse_data ();
}

}//::webmuzzle
