#include "Class7.h"


Class7::Class7( string name ) : _name( name + "_7" ), Class4( name + "_7" ), Class5( name + "_7" ), Class1( name + "_7" )
{
}

string Class7::GetName()
{
	return _name;
}
