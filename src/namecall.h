//@(#) Mapping function's pointer for named call
//Author: Andrew Wingorodov <mail@andr.mobi>
//$Id$

#ifndef	CXX_NAMECALL_H
#define	CXX_NAMECALL_H 1

#include <map>
#include <stdexcept>

using namespace std;

namespace cxx {

///\brief Map of function's pointer
template <typename NameT, typename FuncPtrT>
class namecall
{
private:

///\brief Mapped functions singleton
std::map< NameT, FuncPtrT >& get_map () {
	static std::map<NameT, FuncPtrT> instance;
	return instance;
}

public:

///\brief Create
namecall (
	  const NameT& name_ ///\param name_ Identifier of function
	, const FuncPtrT& func_ ///\param Pointer to function
) { 
	get_map()[name_] = func_;
}

///\brief Cascade static init
namecall< NameT, FuncPtrT >&operator() (
	  const NameT& name_ ///\param name_ Identifier of function
	, const FuncPtrT& func_ ///\param Pointer to function
) { 
	get_map()[name_] = func_;
	return *this;
}

///\brief Setup new function
inline void call (
	  const NameT& name_ ///\param name_ Identifier of function
	, const FuncPtrT& func_ ///\param Pointer to function
) {
	get_map()[name_] = func_;
}

///\brief Trying get function by identifier
///\return Function pointer
///\except Invalid argument if name not found
inline
FuncPtrT& operator[] (
	  const NameT& name_ ///\param name_ Identifier of function
) {
	if ( get_map().find (name_) == get_map().end())
		throw invalid_argument(name_+" function not exists");

	return get_map()[name_];
}


}; //namecall

}//::cxx

#endif //CXX_NAMECALL_H
