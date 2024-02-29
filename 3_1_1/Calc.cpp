#include "Calc.h"


void Calc::Count( char operation, int a, int b )
{
    switch ( operation )
    {
        case '+': _result = a + b; break;
        case '-': _result = a - b; break;
        case '*': _result = a * b; break;
        case '%': _result = a % b; break;
        default: break;
    }
}

void Calc::FirstOperation( char operation, int a, int b )
{
    Count( operation, a, b );
}

void Calc::NextOperation( char operation, int num )
{
    Count( operation, _result, num );
}

int Calc::GetResult()
{
    return _result;
}
