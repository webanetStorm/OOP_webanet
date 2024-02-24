#include <iostream>
#include <iomanip>
#include "ArrayHandler.h"

using namespace std;


ArrayHandler::ArrayHandler( int size )
{
    _size = size;
}

void ArrayHandler::PrintArraySize()
{
    cout << "N = " << _size;
}

void ArrayHandler::ReadArray()
{
    for ( int i = 0; i < _size; i++ )
        cin >> _array[i];
}

void ArrayHandler::PrintArray()
{
    for ( int i = 0; i < _size; i++ )
        cout << setw( 5 ) << _array[i];
}

void ArrayHandler::ReverseArray()
{
    for ( int i = 0; i < _size / 2; i++ )
    {
        int temp = _array[i];

        _array[i] = _array[_size - 1 - i];
        _array[_size - 1 - i] = temp;
    }
}
