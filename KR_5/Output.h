#ifndef __OUTPUT__H
#define __OUTPUT__H


#include "Base.h"


class Output : public Base
{

public:

	Output( Base* pParent, string name = "Output object" );

	virtual void Handler( string command );

};


#endif
