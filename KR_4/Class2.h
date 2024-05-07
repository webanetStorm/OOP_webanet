#ifndef __CL_2_H__
#define __CL_2_H__
#include "Base.h"

class cl_2 : public Base
{
public:
	cl_2( Base* pParent, string _name );
	void signal_f( string& msg );
	void handler_f( string msg );
};
#endif