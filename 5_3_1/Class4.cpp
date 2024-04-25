#include "Class4.h"


Class4::Class4( int a1, int a2, int a3, int a4 ) : Class3( a1, a2, a3 ), _a4( a4 )
{
}

int Class4::Evaluate( int value )
{
	return Class3::Evaluate( value ) + _a4 * value * value * value * value;
}
