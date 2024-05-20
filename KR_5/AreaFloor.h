#ifndef __AREAFLOOR__H
#define __AREAFLOOR__H

#include "Area.h"


class AreaFloor : public Area
{
public:
	AreaFloor( Base* parent, string name );
	virtual void handler_f( string command );

private:
	int n = 0;
	int m = 0;
};

#endif
