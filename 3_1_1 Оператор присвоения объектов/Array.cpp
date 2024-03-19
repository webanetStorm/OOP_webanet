#include <iostream>
#include "Array.h"

using namespace std;


Array::Array( int value )
{
	this->Arr = new int[value];

	for ( int i = 0; i < value; i++ )
		this->Arr[i] = value;
}

Array::~Array()
{
	delete[] this->Arr;
}

void Array::Print()
{
	for ( int i = 0; i < this->Arr[0]; i++ )
	{
		cout << this->Arr[i];
		if ( i < this->Arr[0] - 1 )
			cout << " ";
	}

	cout << endl;
}