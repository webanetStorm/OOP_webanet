#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

using namespace std;


int main()
{
	int result = 0;
	long long int number;
	cin >> number;

	if ( number == 0 )
		result = 1;

	while ( number > 0 )
	{
		number /= 10;
		result++;
	}

	cout << "Number of digits: " << result;


	return 0;
}
