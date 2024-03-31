#include <iostream>
#include "Parent.h"

using namespace std;


void Parent::Method1( int value )
{
	_a = value * 2;
}

Parent::Parent( int a, int b ) : B( b )
{
	Method1( a );
}

void Parent::SetValues( int a, int b )
{
	Method1( a );
	B = b;
}

void Parent::Print()
{
	cout << _a << "    " << B << endl;
}
