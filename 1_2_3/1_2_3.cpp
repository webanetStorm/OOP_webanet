#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Number.h"

using namespace std;


int main()
{
	long long int n;
	cin >> n;

	Number obj;
	obj.SetN( n );
	obj.CountDigits();
	cout << "n = " << obj.GetN() << endl;
	cout << "N = " << obj.GetCount();


	return 0;
}
