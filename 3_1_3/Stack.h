#pragma once

#include <string>


using namespace std;


class Stack
{

private:

	string _name;

	int _size;

	int _currentSize;

	int* _elements;


public:

	Stack( string, int );

	~Stack();

	bool Push( int );

	bool Pop( int& );

	string GetName();

	int GetSize();

	int GetCurrentSize();

};
