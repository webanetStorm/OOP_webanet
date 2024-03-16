#include <iostream>
#include "Class.h"

using namespace std;


int main()
{
	int i_data;
	cin >> i_data;

	Class* pObj = new Class( i_data );

	pObj->PrintValues();
	pObj->FuncA();
	pObj->PrintValues();

	cin >> i_data;
	if ( i_data > pObj->B )
		pObj->B = i_data * 8;

	pObj->PrintValues();
	pObj->CallFuncB();
	pObj->PrintValues();


	return 0;
}
