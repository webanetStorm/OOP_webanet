#pragma once
#include <iostream>


using namespace std;


class Class
{

private:

	int _a;


	void FuncB();


public:

	int B;


	Class( int );

	void FuncA();

	void CallFuncB();

	void PrintValues();

};

