#include <iostream>
#include "Array.h"

using namespace std;


Array::Array( int value )
{
	this->_arr = new int[value];
	for ( int i = 0; i < value; i++ )
		this->_arr[i] = value;
}

Array::~Array()
{
	delete[] this->_arr;
}

void Array::Print()
{
	for ( int i = 0; i < this->_arr[0]; i++ )
	{
		cout << this->_arr[i];

		if ( i < this->_arr[0] - 1 )
			cout << "  ";
	}

	cout << endl;
}

int* Array::GetArray()
{
	return this->_arr;
}

void Array::SetArray( int* arr )
{
	this->_arr = arr;
}
