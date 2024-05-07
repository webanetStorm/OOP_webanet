#ifndef __CL_APPLICATION_H__
#define __CL_APPLICATION_H__
#include "Base.h"
#include "Class1.h"
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"
#include "Class5.h"
#include "Class6.h"
class cl_application : public Base
{
public:
	cl_application( Base* pParent );
	void build_tree_objects();
	int exec_app();
	void build_commands();
	void setConnections();
};
#endif