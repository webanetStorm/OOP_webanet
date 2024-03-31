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

	void CreateArray();

	void Input();

	void Method1();

	void Method2();

	void Print();

	int Sum();

	int* GetArrayPointer();

	void SetArrayPointer( int* arr );

};
