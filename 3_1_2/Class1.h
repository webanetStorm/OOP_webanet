#pragma once


class Class2;


class Class1
{

private:

	int _a;


public:

	Class1( int );

	friend int Max( Class1, Class2 );

};
