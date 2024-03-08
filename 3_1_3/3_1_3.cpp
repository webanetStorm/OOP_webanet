#include <iostream>
#include <iomanip>
#include "Stack.h"


int main()
{
    string name;
    int size, value;

    cin >> name >> size;
    Stack stack1( name, size );

    cin >> name >> size;
    Stack stack2( name, size );


    while ( cin >> value )
    {
        if ( !stack1.Push( value ) )
            break;
        if ( !stack2.Push( value ) ) 
            break;
    }


    cout << stack1.GetName() << ' ' << stack1.GetSize() << endl;
    cout << stack2.GetName() << ' ' << stack2.GetSize() << endl;
    cout << left << setw( 15 ) << stack1.GetName() << stack2.GetName() << endl;

    while ( stack1.GetCurrentSize() > 0 || stack2.GetCurrentSize() > 0 )
    {
        stack1.Pop( value ) ? cout << right << setw( 15 ) << value : cout << setw( 15 ) << "";

        if ( stack2.Pop( value ) )
            cout << right << setw( 15 ) << value;

        cout << endl;
    }


	return 0;
}
