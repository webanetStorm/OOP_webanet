#ifndef __CONTROLLER__H
#define __CONTROLLER__H


#include "Base.h"

class Controller : public Base
{

private:

	int _n = 0, _m = 0, _floorNumber = 0, _boomAngle = 0, _boomLength = 1, _squareNumber;

	string _cargoId = "";


public:

	Controller( Base* pParent, string name = "Controller object" );

	void FindCargo( string id );

	void Work( string id = 0 );

	virtual void Handler( string command );

};


#endif
