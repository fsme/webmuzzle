//@(#) Webmuzzle's Request processing
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "request.h"

namespace webmuzzle {

//
void request::processing()
{
	dbh = dbase::pool().open( Data->Cookie["SID"]
							, Data->APRreq->connection->remote_ip );
	Data->ClientBlock.parse();
	dbh.FSM()->init(Data);
	for(;;) {
		try { dbh.FSM()->do_http_request();
		} catch (const event::logout& e) { dbh.FSM()->do_logout();
		} catch (const event::login& e)  { dbh.FSM()->do_login();
		} catch (const event::login_fail& e) { dbh.FSM()->do_login_failure();
		} catch (event::next_state& e) {
					dbh.FSM( e.next_state_is());
					if ( e.is_done()) break;
		} catch (const event::is_done& e)  { break;
		}
	break;
	}//processing loop (FSM's Event/State table implementation)

	///Html.replace( "<h1>You are inside</h1>", "MAINTABLE" );
}

/*****

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
	&& ( Data.ClientBlock["user"].size() > 0 )
	) {
		try {
			dbh.open ( Req->pool
					, Data.ClientBlock ["driver"]
					, Data.ClientBlock ["user"]
					, Data.ClientBlock ["password"]
					, Data.ClientBlock ["host"]
					, Data.ClientBlock ["port"]
					, Data.ClientBlock ["path"]
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

**************************/

}//::webmuzzle
