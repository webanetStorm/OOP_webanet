#include <iostream>
#include "Class1.h"
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"


int main()
{
	string name;
	int num;

	cin >> name >> num;


	Class1* pObj = ( Class1* )new Class4( name, num );
	pObj->Print();
	( (Class2*)pObj )->Print();
	( (Class3*)pObj )->Print();
	( (Class4*)pObj )->Print();

	delete pObj;


	return 0;
}
