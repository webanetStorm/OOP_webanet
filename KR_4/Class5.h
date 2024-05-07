#ifndef __CL_5_H__
#define __CL_5_H__
#include "Base.h"

class cl_5 : public Base
{
public:
	cl_5( Base* pParent, string _name );
	void signal_f( string& msg );
	void handler_f( string msg );
};
#endif