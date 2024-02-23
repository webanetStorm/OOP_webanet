#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Triangle.h"

using namespace std;


int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	Triangle ABC( a, b, c );

	cout << "P=" << ABC.Perimetr() << endl << "S=" << ABC.Square();


	return 0;
}
