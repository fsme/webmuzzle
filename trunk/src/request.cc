//@(#) Webmuzzle's Request processing
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "request.h"

namespace webmuzzle {

//
void request::processing()
{
	Data.parse();
	dbh = dbase::pool().open( Cookie["SID"], Req->connection->remote_ip );

	if ( !check_login()) return;

	if (0 == Cookie["DATABASE"].size())
	{ /// Show databases
			
	}
	Html.replace( "<h1>You are inside</h1>", "MAINTABLE" );
}

//
bool request::check_login()
{
	if ( 0 == string("/logout").compare(0, sizeof("/logout"), Req->uri)
	) {
		dbh.close();
		Html.loginform (true);
		Html.replace(" Good bye, you're welcome ", "MESSAGE");
		return false;
	}

	if ( !dbh.is_open()
	&& ( Data["user"].size() > 0 )
	) {
		try {
			dbh.open ( Req->pool
					, Data["driver"]
					, Data["user"]
					, Data["password"]
					, Data["host"]
					, Data["port"]
					, Data["path"]
			);
		} catch (const std::exception& e) {
			/// Log e.what();
		}
		if ( !dbh.is_open()) {
			Html.loginform (true);
			Html.replace(" Login failure ", "MESSAGE");
			return false;
		}
	}

	if ( dbh.is_open())
	{
		Html.loginform (false);
		Html.replace("", "MESSAGE");
		return true;
	} else {
		Html.loginform (true);
		Html.replace(" Login please ", "MESSAGE");
		return false;
	}
}

//
void request::response ()
{
	Cookie.output(Req);
	::ap_set_content_type(Req, "text/html; charset=UTF-8");
	::ap_set_content_length( Req, static_cast<apr_off_t>(Html.str().size()) );
	::ap_rprintf(Req, "%s", Html.str().c_str());
}


}//::webmuzzle
