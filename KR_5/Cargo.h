#ifndef __CARGO__H
#define __CARGO__H


#include "Base.h"


class Cargo : public Base
{

public:

	int Length, Width, Height;


	Cargo( Base* pParent, string name, int l, int w, int h );

};


#endif
