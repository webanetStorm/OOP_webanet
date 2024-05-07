#ifndef __CL_4_H__
#define __CL_4_H__
#include "Base.h"

class cl_4 : public Base
{
public:
	cl_4( Base* pParent, string _name );
	void signal_f( string& msg );
	void handler_f( string msg );
};
#endif