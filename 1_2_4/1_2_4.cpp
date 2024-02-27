#include <iostream>
#include "Calc.h"

using namespace std;


int main()
{
    Calc calc;

    int a, b;
    char operation;


    cin >> a >> operation >> b;
    calc.FirstOperation( operation, a, b );

    cin >> operation >> b;
    calc.NextOperation( operation, b );

    cin >> operation >> b;
    calc.NextOperation( operation, b );

    cout << calc.GetResult();


    return 0;
}
