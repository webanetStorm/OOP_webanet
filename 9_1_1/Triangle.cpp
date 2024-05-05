#include "Triangle.h"
#include <math.h>


Triangle::Triangle( int a, int b, int c ) : _a( a ), _b( b ), _c( c )
{
}

int Triangle::Perimetr()
{
	return _a + _b + _c;
}

double Triangle::Square()
{
	double p = Perimetr() / 2.0;

	return sqrt( p * ( p - _a ) * ( p - _b ) * ( p - _c ) );
}

Triangle Triangle::operator+( Triangle ABC )
{
	Triangle triangle( _a + ABC._a, _b + ABC._b, _c + ABC._c );

	return triangle.IsValid() ? triangle : *this;
}

Triangle Triangle::operator-( Triangle ABC )
{
	Triangle triangle( _a - ABC._a, _b - ABC._b, _c - ABC._c );

	return triangle.IsValid() ? triangle : *this;
}

bool Triangle::IsValid()
{
	return ( _a + _b > _c ) && ( _a + _c > _b ) && ( _b + _c > _a );
}

void Triangle::Print()
{
	std::cout << "a = " << _a << "; b = " << _b << "; c = " << _c << "." << std::endl;
}
