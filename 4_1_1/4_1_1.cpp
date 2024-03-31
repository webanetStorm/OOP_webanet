#include <iostream>
#include "Parent.h"
#include "Child.h"

using namespace std;


int main()
{
    int a, b;
    cin >> a >> b;


    Child obj( a, b );

    obj.Parent::Print();
    obj.Print();

    if ( a > 0 )
    {
        obj.Parent::SetValues( a - 1, b - 1 );
        obj.SetValues( a + 1, b + 1 );

        obj.Print();
        obj.Parent::Print();
    }
    else
    {
        obj.Parent::SetValues( a + 1, b + 1 );
        obj.SetValues( a - 1, b - 1 );

        obj.Parent::Print();
        obj.Print();
    }


    return 0;
}
