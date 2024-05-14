#pragma once

#include "Base.h"


class Cargo : public Base
{

private:

	double _length, _width, _height;


public:

	Cargo( Base* pParent, double length, double width, double height, string name ) : Base( pParent, name ), _length( length ), _width( width ), _height( height )
	{
	};

	void SignalF( string& message );

	void HandlerF( string message );

};
