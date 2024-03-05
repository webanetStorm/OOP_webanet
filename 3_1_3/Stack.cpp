#include "Stack.h"


Stack::Stack( string name, int size ) : _name( name ), _size( size )
{
    if ( size < 1 )
        _size = 1;
}

bool Stack::Push( int value )
{
    if ( _elements.size() < _size )
    {
        _elements.push_back( value );

        return true;
    }

    return false;
}

bool Stack::Pop( int& value )
{
    if ( !_elements.empty() )
    {
        value = _elements.back();
        _elements.pop_back();

        return true;
    }

    return false;
}

vector<int> Stack::GetElements()
{
    return _elements;
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
    return _elements.size();
}
