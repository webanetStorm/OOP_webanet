#ifndef __INPUT__H
#define __INPUT__H

#include "Base.h"

class Input : public Base
{
public:
	Input( Base* parent, string name = "Input object" );
	virtual void handler_f( string command );

	void init_data();
};

#endif
