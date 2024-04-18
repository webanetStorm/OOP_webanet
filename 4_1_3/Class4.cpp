#include "Class4.h"


Class4::Class4( string name ) : _name( name + "_4" ), Class1( name + "_4" )
{
}

string Class4::GetName()
{
	return _name;
}
