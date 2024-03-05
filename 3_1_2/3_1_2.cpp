#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Class1.h"
#include "Class2.h"

using namespace std;


int Max( Class1 obj1, Class2 obj2 )
{
	int m = obj2._b > obj2._c ? obj2._b : obj2._c;

	return m > obj1._a ? m : obj1._a;
}

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	Class1 obj1( a );
	Class2 obj2;
	obj2.SetBC( b, c );

	cout << Max( obj1, obj2 );


	return 0;
}
