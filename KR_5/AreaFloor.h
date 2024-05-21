#ifndef __AREAFLOOR__H
#define __AREAFLOOR__H


#include "Area.h"


class AreaFloor : public Area
{

private:

	int _n = 0, _m = 0;


public:

	AreaFloor( Base* pParent, string name );

	virtual void Handler( string command );

};


#endif
