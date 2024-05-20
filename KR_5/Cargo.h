#ifndef __CARGO__H
#define __CARGO__H

#include "Base.h"


class Cargo : public Base
{
public:
	Cargo( Base* parent, string name, int l, int w, int h );

	int l, w, h;
};

#endif
