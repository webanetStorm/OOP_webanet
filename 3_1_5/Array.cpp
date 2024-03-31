#include <iostream>
#include "Array.h"

using namespace std;


Array::Array( const Array& obj )
{
	cout << "Copy constructor" << endl;

	_size = obj._size;
	_arr = new int[_size];

	for ( int i = 0; i < _size; i++ )
		_arr[i] = obj._arr[i];
}

Array::Array( int size )
{
	cout << "Constructor set" << endl;

	_size = size;
	_arr = new int[_size];
}

Array::Array()
{
	cout << "Default constructor" << endl;
}

Array::~Array()
{
	cout << "Destructor" << endl;

	delete[] _arr;
}

void Array::CreateArray()
{
	_arr = new int[_size];
}

void Array::Input()
{
	for ( int i = 0; i < _size; i++ )
		cin >> _arr[i];
}

void Array::Method1()
{
	for ( int i = 0; i < _size; i += 2 )
		_arr[i] += _arr[i + 1];
}

void Array::Method2()
{
	for ( int i = 0; i < _size; i += 2 )
		_arr[i] = _arr[i] * _arr[i + 1];
}

void Array::Print()
{
	for ( int i = 0; i < _size; i++ )
	{
		cout << _arr[i];

		if ( i < _size - 1 )
			cout << "  ";
	}

	cout << endl;
}

int Array::Sum()
{
	int result = 0;

	for ( int i = 0; i < _size; i++ )
		result += _arr[i];

	return result;
}

int* Array::GetArrayPointer()
{
	return _arr;
}

void Array::SetArrayPointer( int* arr )
{
	_arr = arr;
}
