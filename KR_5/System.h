#ifndef __SYSTEM__H
#define __SYSTEM__H


#include "Base.h"
#include "Input.h"
#include "Controller.h"
#include "Area.h"
#include "AreaFloor.h"
#include "Output.h"
#include "Cargo.h"


class System : public Base
{

private:

	string _data = "";


public:

	System( Base* pParent, string name = "System" );

	virtual void Signal( string& command );

	virtual void Handler( string command );

	void BuildTreeObjects();

	int ExecApp();

};


#endif
