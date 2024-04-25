#include "Class1.h"


Class1::Class1( int a1 ) : _a1( a1 )
{
}

int Class1::Evaluate( int value )
{
	return _a1 * value;
}
