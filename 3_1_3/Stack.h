#pragma once

#include <vector>
#include <string>

using namespace std;


class Stack
{

private:

	string _name;

	int _size;

	vector<int> _elements;


public:

	Stack( string, int );

	bool Push( int );

	bool Pop( int& );

	string GetName();

	int GetSize();

	int GetCurrentSize();

};
