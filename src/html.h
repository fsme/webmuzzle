//@(#) HTML muzzle for response
//Author: Andrew Wingorodov <mail@andr.mobi>
//$Id$

#ifndef	WEBMUZZLE_HTML_H
#define	WEBMUZZLE_HTML_H

#include <string>
#include <map>

using namespace std;

namespace webmuzzle {

///\brief HTML document for HTTP-response
class html
{
private:
static string pattern;
static string loginform_str;
	string result;

public:
///\brief Create
html () : result(pattern) {}

///\brief Clear result (free memory)
void clear () { result.clear(); }

///\brief Set message : replace pattern or previous message
void replace (
	  const string& msg_///\param msg_ Message text
	, const string& mark_///\param mark_ Point for replace
) {
	static map< string, string > prev;
	string Mark = "<!--[["+mark_+"]]-->";

	string::size_type pos;
	if ( (pos = result.find(Mark)) != string::npos
	&& msg_.size() > 0
	) {
		result.replace(pos, Mark.size(), msg_);
		prev [Mark] = msg_;
	}
	else if ( prev [Mark].size() > 0
		&&  (pos = result.find( prev[Mark] )) != string::npos)
		{
			if ( msg_.size() > 0 ) {
				result.replace(pos, prev [Mark].size(), msg_);
				prev [Mark] = msg_;
			}
			else
				result.replace(pos, prev [Mark].size(), Mark);
				prev [Mark] = Mark;
		}
}

///\brief Visible or hidden element by Id through javascript
void visible (
	  const string& elem_///\param Element Id
	, const bool enable_///\param Visible if true, else hidden
) {
}

///\brief Visible or hidden login form
void loginform (
	  const bool enable_///\param Visible if true, hidden else
) {
	if (enable_)
		replace ( loginform_str, "MAINTABLE" );
	else
		replace ( "", "MAINTABLE" );
}

///\brief Get result as string
const string& str () const { return result; }

}; //html

}//::webmuzzle

#endif //WEBMUZZLE_HTML_H
