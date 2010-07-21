//@(#) Webmuzzle's Request processing
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "request.h"

namespace webmuzzle {

//
void request::exec()
{
	dbh = dbase::pool().open( Cookie["SID"], Req->connection->remote_ip );
	if ( !dbh.is_open()
	) {
		
	}
}

//
void request::response ()
{
	Cookie.output(Req);
	::ap_set_content_type(Req, "text/html; charset=UTF-8");

	ap_rputs( "<HTML>\n", Req);
	ap_rputs( " <HEAD>\n", Req);
	ap_rputs( " <TITLE>TXTLib wordwide text library</TITLE>\n", Req);
	ap_rputs( " </HEAD>\n", Req);
	ap_rputs( " <BODY>\n", Req);
	ap_rputs( "<H1>TXTLib wordwide text library</H1>\n", Req);

	ap_rprintf(Req, "<H2>%s</H2>\n", Cookie["SID"].c_str() );

	ap_rputs( " </BODY>\n", Req);
	ap_rputs( "</HTML>\n", Req);
}


}//::webmuzzle
