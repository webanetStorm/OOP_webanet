#pragma once


#include "Class3.h"

class Class4 : public Class3
{

protected:

	int _a4;


public:

	Class4( int a1, int a2, int a3, int a4 );

	virtual int Evaluate( int );

};
