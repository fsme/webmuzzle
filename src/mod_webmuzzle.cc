//@(#) HTTP-SQL framework Webmuzzle (Apache module)
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "mod_webmuzzle.h"

namespace webmuzzle {

///\brief Allocator dir config
static
void* create_dir_config (
	  apr_pool_t *p
	, char *dirspec
) {
    webmuzzle_cfg *cfg =
		(webmuzzle_cfg*) apr_pcalloc( p, sizeof(webmuzzle_cfg));

    cfg->enabled = 1;
    return (void*) cfg;
}

///\brief Allocator server config
static
void* create_server_config (
	  apr_pool_t *p
	, server_rec *s
) {
    webmuzzle_cfg *cfg =
		(webmuzzle_cfg*) apr_pcalloc( p, sizeof(webmuzzle_cfg));

    cfg->enabled = 1;
    return (void*) cfg;
}

///\brief Webmuzzle handler
static
int webmuzzle_handler (
	  request_rec *r ///\param r Request
) {
try {
	if ( string("webmuzzle") != r->handler)
		return DECLINED;

	auto_ptr<request> Request( new request(r));
	Request->processing();

} catch (const std::exception& e) {
	simple_http_echo (r, e.what());

} catch (...) {
	simple_http_echo (r, "Unknown except");
}

	return OK;
}


///\brief Webmuzzle register
static
void webmuzzle_register_hooks (
	  apr_pool_t *pool
) {
	::ap_hook_handler( webmuzzle_handler, NULL, NULL, APR_HOOK_FIRST);
	::apr_dbd_init (pool);
}

extern "C"
{
	module AP_MODULE_DECLARE_DATA webmuzzle_module =
	{
	  STANDARD20_MODULE_STUFF
    , create_dir_config
    , NULL
    , create_server_config
    , NULL
    , directives
    , webmuzzle_register_hooks
	};
}


}//::webmuzzle
