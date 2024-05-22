#include "AreaFloor.h"


AreaFloor::AreaFloor( Base* parent, string name ) : Area( parent, name )
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
		vector<string> commands = this->Explode( command );

		this->_n = stoi( commands[0] );
		this->_m = stoi( commands[1] );

		this->SetCountSqr( this->_n * this->_m / 16 );
	}
}
