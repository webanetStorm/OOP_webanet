#include "Class3.h"


Class3::Class3( int a1, int a2, int a3 ) : Class2( a1, a2 ), _a3( a3 )
{
}

int Class3::Evaluate( int value )
{
	return Class2::Evaluate( value ) + _a3 * value * value * value;
}
