//@(#) Apache module HTTP-SQL framework Webmuzzle (header)
//Author: Andrew Wingorodov <mail@andr.mobi>
//$Id$

#ifndef	MOD_WEBMUZZLE_H
#define	MOD_WEBMUZZLE_H

#include <string>
#include <memory>
#include <stdexcept>

#include "httpd.h"
#undef AP_HAVE_DESIGNATED_INITIALIZER
#include "http_config.h"

#include "request.h"
#include "dbpool.h"

namespace webmuzzle {

extern "C" module AP_MODULE_DECLARE_DATA webmuzzle_module;

///\brief  Webmuzzle configuration
typedef
struct webmuzzle_cfg {
    int enabled;
	const char* dbase;
}
 webmuzzle_cfg;

///\brief Directives from Apache config
static
const command_rec directives[] = {
	{NULL}
};

typedef	std::pair<apr_off_t, apr_off_t>	byte_count_t;
///\brief
inline byte_count_t* module_cfg ( request_rec *r ) {
return static_cast<byte_count_t*>(\
	ap_get_module_config( r->connection->conn_config, &webmuzzle_module) );
}

///\brief Simple HTTP response
inline
void simple_http_echo (
	  request_rec* req_///\param req_
	, const char* msg_///\param msg_
) {
	::ap_set_content_type ( req_, "text/html; charset=UTF-8");
	::ap_set_content_length( req_, strlen(msg_) );
	::ap_rprintf( req_, "%s", msg_);
}

}//::webmuzzle

#endif //MOD_WEBMUZZLE_H
