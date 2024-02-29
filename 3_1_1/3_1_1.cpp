#include <iostream>
#include "Calc.h"

using namespace std;


int main()
{
    Calc calc;

    int a, b, counter = 2;
    char operation;


    cin >> a >> operation >> b;
    calc.FirstOperation( operation, a, b );

    while ( cin >> operation )
    {
        if ( operation == 'C' )
            break;

        cin >> b;
        calc.NextOperation( operation, b );
        

        if ( counter % 3 == 0 )
            cout << calc.GetResult() << endl;

        counter++;
    }


    return 0;
}
