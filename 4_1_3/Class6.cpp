#include "Class6.h"


Class6::Class6( string name ) : _name( name + "_6" ), Class2( name + "_6" ), Class3( name + "_6" )
{
}

string Class6::GetName()
{
	return _name;
}
