#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Array.h"

using namespace std;


Array Func( int size )
{
	Array local( size );

	return local;
}

int main()
{
	int size;
	cin >> size;


	if ( size <= 2 || size % 2 != 0 )
	{
		cout << size << '?' << endl;

		return 0;
	}


	cout << size << endl;

	Array firstObj;
	firstObj = Func( size );
	firstObj.CreateArray();
	firstObj.Input();
	firstObj.Method2();

	Array secondObj = firstObj;
	secondObj.Method1();

	firstObj.Print();
	cout << firstObj.Sum() << endl;

	secondObj.Print();
	cout << secondObj.Sum() << endl;


	return 0;
}
