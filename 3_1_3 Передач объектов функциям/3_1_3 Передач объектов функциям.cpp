#include <iostream>
#include "Array.h"

using namespace std;


void Func( Array obj )
{
    cout << obj.Method2() << endl;
}

int main()
{
    int size;
    cin >> size;


    if ( size <= 2 || size % 2 != 0 )
    {
        cout << size << "?" << endl;

        return 1;
    }

    cout << size << endl;

    Array a( size );
    a.Input();
    Func( a );
    cout << a.Method1() << endl;


    return 0;
}
