#include <iostream>
#include "Class1.h"


Class1::Class1( string name, int num ) : _name( name + "_1" ), _num( num )
{
}

void Class1::Print()
{
	cout << _name << ' ' << _num << endl;
}
