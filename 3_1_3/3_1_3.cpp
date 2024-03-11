#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"


int main()
{
	string name1, name2;
	int size1, size2, value;

	cin >> name1 >> size1 >> name2 >> size2;

	Stack stack1( name1, size1 ), stack2( name2, size2 );


	for ( int i = 0; i < max( size1, size2 ); i++ )
	{
		cin >> value;

		if ( !stack1.Push( value ) )
			break;
		if ( !stack2.Push( value ) )
			break;
	}


	cout << stack1.GetName() << ' ' << stack1.GetSize() << endl;
	cout << stack2.GetName() << ' ' << stack2.GetSize() << endl;
	cout << left << setw( 15 ) << stack1.GetName() << setw( 15 ) << stack2.GetName() << endl;

	while ( stack1.GetCurrentSize() > 0 )
	{
		if ( stack1.Pop( value ) )
			cout << right << setw( 15 ) << value;
		if ( stack2.Pop( value ) )
			cout << right << setw( 15 ) << value << endl;
	}


	return 0;
}
