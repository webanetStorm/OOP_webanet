#include <stdlib.h>
#include <stdio.h>
#include "TestClass.h"


int main()
{
	TestClass* pObj = new TestClass();
	delete pObj;
	
	return 0;
}