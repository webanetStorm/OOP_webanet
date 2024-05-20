#include "AreaFloor.h"

AreaFloor::AreaFloor( Base* parent, string name ) : Area( parent, name )
{
}

void AreaFloor::handler_f( string command )
{
	if ( command == "Floor condition" )
	{
		check_cargos( command );
	}
	else if ( command.find( "Cargo condition" ) != string::npos )
	{
		vector<string> words = get_words( command );
		get_condition( words[2] );
	}
	else
	{
		vector<string> words = get_words( command );

		n = stoi( words[0] );
		m = stoi( words[1] );
		set_count_sqr( n * m / 16 );
	}
}
