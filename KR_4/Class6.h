#ifndef __CL_6_H__
#define __CL_6_H__
#include "Base.h"

class cl_6 : public Base
{
public:
	cl_6( Base* pParent, string _name );
	void signal_f( string& msg );
	void handler_f( string msg );
};
#endif