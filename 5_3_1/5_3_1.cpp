#include <iostream>
#include "Class1.h"
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"


int main()
{
	int a1, a2, a3, a4;
	std::cin >> a1 >> a2 >> a3 >> a4;
	std::cout << "a1 = " << a1 << "    a2 = " << a2 << "    a3 = " << a3 << "    a4 = " << a4 << std::endl;

	Class4* poly = new Class4( a1, a2, a3, a4 );

	int x, classNum;
	while ( true )
	{
		std::cin >> x;
		if ( x == 0 )
			break;

		std::cin >> classNum;

		Class1* chosenPoly = nullptr;
		switch ( classNum )
		{
			case 1: chosenPoly = new Class1( a1 ); break;
			case 2: chosenPoly = new Class2( a1, a2 ); break;
			case 3: chosenPoly = new Class3( a1, a2, a3 ); break;
			case 4: chosenPoly = new Class4( a1, a2, a3, a4 ); break;
			default: continue;
		}

		std::cout << "Class " << classNum << "    F(" << x << ") = " << chosenPoly->Evaluate( x ) << std::endl;
		delete chosenPoly;
	}

	delete poly;


	return 0;
}
