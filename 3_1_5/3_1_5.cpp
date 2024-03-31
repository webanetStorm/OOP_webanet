#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Array.h"

using namespace std;


Array* Func( int size )
{
	Array* obj = new Array( size );

	obj->CreateArray();
	obj->Input();
	obj->Method2();

	return obj;
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

	Array* firstObj;
	firstObj = Func( size );
	firstObj->Method1();

	Array* secondObj = new Array( *firstObj );
	secondObj->Method2();

	firstObj->Print();
	cout << firstObj->Sum() << endl;

	secondObj->Print();
	cout << secondObj->Sum() << endl;

	secondObj->Print();
	cout << secondObj->Sum() << endl;

	delete firstObj;
	delete secondObj;


	return 0;
}
