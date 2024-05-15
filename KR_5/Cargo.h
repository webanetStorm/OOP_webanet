#pragma once

#include "Base.h"
#include "CargoPlatform.h"


class Cargo : public CargoPlatform
{

private:

	double _length, _width, _height;


public:

	Cargo( Base* pParent, double length, double width, double height, string name );

	void SignalF( string& message );

	void HandlerF( string message );

};
