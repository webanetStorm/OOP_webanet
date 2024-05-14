#pragma once

#include "Base.h"
#include <map>


class CargoPlatform : public Base
{

private:

	map<int, vector<string>> _cargoes;


public:

	CargoPlatform( Base* pParent, string name );

	void SignalF( string& message );

	void HandlerF( string message );

	void AddCargo( int square, string cargoId );

	void RemoveCargo( string cargoId );

};
