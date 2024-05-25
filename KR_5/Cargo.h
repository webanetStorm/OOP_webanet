#ifndef __CARGO__H
#define __CARGO__H


#include "Base.h"


class Cargo : public Base
{

private:

	int _length, _width, _height;


public:

	Cargo( Base* pParent, string name, int length, int wodth, int height );

};


#endif
