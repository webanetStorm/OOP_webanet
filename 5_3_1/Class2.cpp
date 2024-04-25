#include "Class2.h"


Class2::Class2( int a1, int a2 ) : Class1( a1 ), _a2( a2 )
{
}

int Class2::Evaluate( int value )
{
	return Class1::Evaluate( value ) + _a2 * value * value;
}
