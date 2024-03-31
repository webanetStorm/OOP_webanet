#include <iostream>
#include "Child.h"

using namespace std;


Child::Child( int a, int b ) : Parent( a, b ), _a( a ), B( b )
{	
}

void Child::SetValues( int a, int b )
{
	_a = a;
	B = b;
}

void Child::Print()
{
	cout << _a << "    " << B << endl;
}
