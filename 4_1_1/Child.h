#pragma once
#include "Parent.h"


class Child : public Parent
{

private:

	int _a;


public:

	int B;


	Child( int, int );

	void SetValues( int, int );

	void Print();

};
