#include <iostream>
#include "TestClass.h"

using namespace std;


TestClass::TestClass()
{
	cout << "Constructor" << endl;
}

TestClass::~TestClass()
{
	cout << "Destructor";
}
