//@(#) Data of HTTP-request (code)
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "request_data.h"

namespace webmuzzle {

//
void request_data::http_response ()
{
	if (0 == APRreq) return;
	Cookie.output( APRreq);
	::ap_set_content_type (  APRreq, "text/html; charset=UTF-8");
	::ap_set_content_length( APRreq
							, static_cast<apr_off_t>(Html.str().size()));
	::ap_rprintf( APRreq, "%s", Html.str().c_str());
	ClientBlock.clear();
	Cookie.clear();
	Html.clear();
	APRreq = 0;
}

}//::webmuzzle
