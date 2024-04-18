#include "Class8.h"


Class8::Class8( string name ) : _name( name + "_8" ), Class6( name + "_8" ), Class7( name + "_8" ), Class1( name + "_8" )
{
}

string Class8::GetName()
{
	return _name;
}
