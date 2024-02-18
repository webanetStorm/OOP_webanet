#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;


int main()
{
	int n = 0, sum = 0;
	cin >> n;
	
	if ( n < 1 )
	{
		cout << "n is wrong (" << n << ")";
	}
	else
	{
		for ( int i = 0; i <= n; i++ )
			sum += i;
		cout << "Sum_n = " << sum;
	}


	return 0;
}