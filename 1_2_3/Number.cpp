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
	long long int tempN = _n;

	if ( _n < 0 )
		_n *= -1;

	while ( tempN > 0 )
	{
		tempN = tempN / 10;
		_count++;
	}

	if ( _n == 0 )
		_count = 1;
}

int Number::GetCount()
{
	return _count;
}
