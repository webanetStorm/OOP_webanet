#ifndef __CL_3_H__
#define __CL_3_H__
#include "Base.h"

class cl_3 : public Base
{
public:
	cl_3( Base* pParent, string _name );
	void signal_f( string& msg );
	void handler_f( string msg );
};
#endif