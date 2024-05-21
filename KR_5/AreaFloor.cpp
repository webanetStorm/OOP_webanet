#include "AreaFloor.h"


AreaFloor::AreaFloor( Base* pParent, string name ) : Area( pParent, name )
{
}

void AreaFloor::Handler( string command )
{
	if ( command == "Floor condition" )
	{
		this->CheckCargos( command );
	}
	else if ( command.find( "Cargo condition" ) != string::npos )
	{
		this->GetCondition( this->Explode( command )[2] );
	}
	else
	{
		vector<string> commands = Explode( command );

		this->_n = stoi( commands[0] );
		this->_m = stoi( commands[1] );

		SetCountSqr( _n * _m / 16 );
	}
}
