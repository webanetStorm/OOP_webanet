#pragma once

#include "Base.h"


class CraneController : public Base
{

private:

	int _houseLength, _houseWidth, _floor, _boomLength, _boomAngle;

	string _cargoId;


public:

	CraneController( Base* pParent, string name );

	virtual void HandlerF( string message );

	void FindCargo( string cargoId );

	void Work( string id = 0 );

	void CraneInfo();

};
