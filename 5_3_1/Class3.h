#pragma once


#include "Class2.h"

class Class3 : public Class2
{

protected:

	int _a3;


public:

	Class3( int a1, int a2, int a3 );

	virtual int Evaluate( int );

};
