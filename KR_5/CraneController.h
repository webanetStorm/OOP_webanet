#pragma once

#include "Base.h"


class CraneController : public Base
{

public:

	CraneController( Base* pParent, string name );

	void SignalF( string& message );

	void HandlerF( string message );

	void MoveCraneToPosition( int position );

	void LiftCargo( string cargoId );

	void DeliverCargo( string cargoId, int position );

};
