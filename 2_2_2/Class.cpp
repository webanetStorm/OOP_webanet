#include "Class.h"


Class::Class( int value ) : _a( value * 3 ), B( value ) {}

void Class::FuncB()
{
	_a += 5;
	B += 7;
}

void Class::FuncA()
{
	_a++;
	B += 4;
}

void Class::CallFuncB()
{
	FuncB();
}

void Class::PrintValues()
{
	cout << "Value of the available property " << B << "; Value of a hidden property " << _a << endl;
}
