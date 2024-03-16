#include <iostream>
#include "Class.h"

using namespace std;


int main()
{
	int i_data;
	cin >> i_data;

	Class obj( i_data );

	obj.PrintValues();
	obj.FuncA();
	obj.PrintValues();

	cin >> i_data;
	obj.B *= i_data;

	obj.PrintValues();
	obj.CallFuncB();
	obj.PrintValues();


	return 0;
}
