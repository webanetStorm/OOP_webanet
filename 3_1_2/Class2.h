#pragma once


class Class1;


class Class2
{

private:

	int _b, _c;


public:

	void SetBC( int, int );

	friend int Max( Class1, Class2 );

};

