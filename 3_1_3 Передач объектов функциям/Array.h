#pragma once


class Array
{

private:

	int* _arr;

	int _size;


public:

	Array( const Array& );

	Array( int size );

	Array();

	~Array();

	void Input();

	int Method1();

	int Method2();

	int Sum();

};
