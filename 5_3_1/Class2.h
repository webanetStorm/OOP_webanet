#pragma once


#include "Class1.h"

class Class2 : public Class1
{

protected:

	int _a2;


public:

	Class2( int a1, int a2 );

	virtual int Evaluate( int );

};
