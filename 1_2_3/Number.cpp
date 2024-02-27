#include "Number.h"
#include <cmath>
#include <iostream>


void Number::SetN( long long int n )
{
	_n = n;
}

long long int Number::GetN()
{
	return _n;
}

void Number::CountDigits()
{
	long long int tempN = _n * ( ( _n > 0 ) - ( _n < 0 ) );

	for ( _count = 0; tempN > 0; _count++ )
		tempN = tempN / 10;

	if ( _n == 0 )
		_count = 1;
}

int Number::GetCount()
{
	return _count;
}
