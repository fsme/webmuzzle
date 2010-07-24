//@(#) HTML muzzle
//Author: Andrew Wingorodov <mail@andr.mobi>
//License: GPLv3
//$Id$

#include "html.h"

namespace webmuzzle {

//Static
std::string html::pattern = "\r\
<?xml version=\"1.0\" encoding=\"UTF-8\"?\r>\
<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"\r\
 	\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">\r\
\r\
<html xmlns=\"http://www.w3.org/1999/xhtml\" lang=\"en\" xml:lang=\"en\">\r\
<head>\r\
<title>Webmuzzle HTTP-SQL Framework</title>\r\
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\" />\r\
<meta name=\"Author\" content=\"Andrew Wingorodov\" />\r\
<meta name=\"Copyright\" content=\"&copy;2010 Metacomputer, Inc.\" />\r\
<meta name=\"keywords\" content=\"HTTP-SQL Framework\" />\r\
<meta name=\"descriptioin\" content=\"HTTP-SQL Framework\" />\r\
<style type=\"text/css\" id=\"defaultcss\">\r\
\r\
HTML BODY {\r\
	font-family: \"Lucida Console\", \"Tahoma\", \"Arial\";\r\
	margin: 0;\r\
	padding: 0;\r\
}\r\
\r\
.copyright {\r\
	text-align: Left;\r\
	font-family: \"Arial\"\r\
	font-size: 10pt\r\
}\r\
\r\
A.copyright:hover { text-decoration: underline; color: #e88222; }\r\
\r\
INPUT.login {\r\
	border:	1px solid;\r\
}\r\
.logout {\r\
		text-align: Right;\r\
}\r\
\r\
.message {\r\
	background-color: Gold;\r\
	color: Grey\r\
}\r\
</style>\r\
\r\
<script type=\"text/javascript\" src=\"http://www.google.com/jsapi\"></script>\r\
<script type=\"text/javascript\">\r\
<!--[[JAVASCRIPT]]-->\r\
</script>\r\
\r\
</head>\r\
<body>\r\
<table width=\"100%\" border=\"0\" cellspacing=\"0\" cellpadding=\"0\">\r\
<colgroup>\r\
	<col width=\"10%\" />\r\
	<col width=\"*\" />\r\
	<col width=\"10%\" />\r\
</colgroup>\r\
<tr>\r\
	<th class=\"navheader\" colspan=\"3\">\r\
	<table border=\"0\" width=\"90%\">\r\
	<colgroup>\r\
		<col width=\"25%\" />\r\
		<col width=\"*\" />\r\
		<col width=\"25%\" />\r\
	</colgroup>\r\
	<tr>\r\
		<td class=\"navheader\">\r\
		</td>\r\
		<th class=\"navheader\">\r\
		</th>\r\
		<td class=\"navheader\">\r\
			<div class=\"logout\" id=\"logoutlink\" style=\"\">\r\
				<a class=\"logout\" href=\"/logout\">Logout</a>\r\
			</div>\r\
		</td>\r\
	</tr>\r\
	</table>\r\
	</th>\r\
</tr>\r\
<tr>\r\
	<th colspan=\"3\">\r\
		<span class=\"message\" id=\"message\"><!--[[MESSAGE]]--></span>\r\
	</th>\r\
</tr>\r\
<tr>\r\
	<th></th>\r\
	<th>\r\
		<div id=\"maintable\">\r\
<!--[[MAINTABLE]]-->\r\
		</div>\r\
	</th>\r\
	<th></th>\r\
</tr>\r\
<tr>\r\
	<th></th>\r\
	<th></th>\r\
	<td>\r\
	</td>\r\
</tr>\r\
</table>\r\
\r\
<p class=\"copyright\">\r\
<a class=\"copyright\" href=\"http://code.google.com/p/webmuzzle/\">\r\
			<b>Web</b>muzzle&trade; project\r\
		</a>\r\
		<br />\r\
		<a class=\"copyright\" href=\"http://andr.mobi/\">\r\
			&copy;2010&nbsp;Andrew&nbsp;Wingorodov\r\
		</a>\r\
</p>\r\
</body>\r\
</html>\r\
";

//Static
std::string html::loginform_str = "\r\
		<form action=\"/\" method=\"post\" id=\"loginform\">\r\
			<select name=\"driver\" id=\"driver\">\r\
				<option value=\"mysql\" selected=\"selected\">MySQL</option>\r\
				<option value=\"pgsql\">PostgreSQL</option>\r\
				<option value=\"oracle\">Oracle</option>\r\
				<option value=\"odbc\">ODBC</option>\r\
			</select>&nbsp;<input class=\"login\" type=\"text\" id=\"host\" name=\"host\" value=\"localhost\"/>:<input class=\"login\" size=\"5\" type=\"text\" id=\"port\" name=\"port\" value=\"\"/>\r\
<br />\r\
<br />\r\
User&nbsp;<input class=\"login\" type=\"text\" id=\"user\" name=\"user\" value=\"\"/>\r\
<br />\r\
Password&nbsp;<input class=\"login\"  size=\"16\" type=\"password\" id=\"password\" name=\"password\" value=\"\"/>\r\
<br />\r\
<input class=\"loginbutton\" type=\"submit\" value=\"Login\"/>\r\
			</form>\r\
";

}//::webmuzzle
