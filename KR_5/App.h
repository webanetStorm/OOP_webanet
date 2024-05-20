#ifndef __APP__H
#define __APP__H

#include "Base.h"
#include "Input.h"
#include "Controller.h"
#include "Area.h"
#include "AreaFloor.h"
#include "Output.h"
#include "Cargo.h"

class App : public Base
{
public:
	App( Base* parent, string name = "System" );
	virtual void signal_f( string& command );
	virtual void handler_f( string command );

	// changed
	void build_tree();
	int exec_app();

	void SHOWTREE();

private:
	string data = "";
};

#endif
