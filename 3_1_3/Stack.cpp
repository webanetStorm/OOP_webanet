#include "Stack.h"


Stack::Stack( string name, int size ) : _name( name ), _size( size > 0 ? size : 1 ), _currentSize( 0 )
{
    _elements = new int[_size];
}

Stack::~Stack()
{
    delete[] _elements;
}

bool Stack::Push( int value )
{
    if ( _currentSize < _size )
    {
        _elements[_currentSize++] = value;

        return true;
    }

    return false;
}

bool Stack::Pop( int& value )
{
    if ( _currentSize > 0 )
    {
        value = _elements[--_currentSize];

        return true;
    }

    return false;
}

string Stack::GetName() 
{
    return _name;
}

int Stack::GetSize()
{
    return _size;
}

int Stack::GetCurrentSize()
{
    return _currentSize;
}
