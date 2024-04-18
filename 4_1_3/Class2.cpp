#include "Class2.h"


Class2::Class2( string name ) : _name( name + "_2" ), Class1( name + "_2" )
{
}

string Class2::GetName()
{
	return _name;
}
