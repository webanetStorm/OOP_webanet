#ifndef __CL_1_H__
#define __CL_1_H__
#include "Base.h"

class cl_1 : public Base
{
public:
	cl_1( Base* pParent, string _name );
	void signal_f( string& msg );
	void handler_f( string msg );
};
#endif