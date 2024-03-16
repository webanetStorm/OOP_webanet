#include "Class.h"


Class::Class( int value ) : _a( value * 2 ), B( value ) {}

void Class::FuncB()
{
	_a += 7;
	B += 5;
}

void Class::FuncA()
{
	_a += 4;
	B++;
}

void Class::CallFuncB()
{
	FuncB();
}

void Class::PrintValues()
{
	cout << "Value of the available property " << B << "; Value of a hidden property " << _a << endl;
}
