#include "Area.h"
#include <iostream>

Area::Area( Base* parent, string name ) : Base( parent, name )
{
}

void Area::handler_f( string command )
{

	if ( command.find( "Condition of the cargo area" ) != string::npos )
		check_cargos( command + " --" );

	else if ( command.find( "Cargo condition" ) != string::npos )
	{
		vector<string> words = get_words( command );
		get_condition( words[2] );
	}
}

void Area::set_count_sqr( int n )
{
	for ( int i = 0; i < n; i++ )
	{
		squares.push_back( vector<Cargo*>() );
	}
}

void Area::check_cargos( string text )
{
	for ( int i = 0; i < squares.size(); i++ )
	{
		if ( squares[i].size() != 0 )
		{
			text += " s " + to_string( i + 1 ) + ":";

			for ( auto it = squares[i].end() - 1; it != squares[i].begin() - 1; it-- )
			{
				text += " " + ( *it )->get_name();
			}
		}
	}
	auto output = get_parent()->get_child( "Output object" );

	emit_signal( SIGNAL_D( Base::signal_f ), output, text );

}

void Area::get_condition( string id )
{

	auto output = get_parent()->get_child( "Output object" );
	string text = "Cargo condition " + id;

	for ( int i = 0; i < squares.size(); i++ )
	{
		if ( squares[i].size() == 0 ) continue;

		for ( auto cargo : squares[i] )
		{
			if ( cargo->get_name() == id )
			{
				string nm = get_name();

				if ( nm.find( "Cargo area" ) != string::npos )
					text += ": in area " + nm.substr( nm.size() - 1 ) + ", square " + to_string( i + 1 );
				else if ( nm.find( "Floor area" ) != string::npos )
				{
					text += ": in floor square " + to_string( i + 1 );
				}


				emit_signal( SIGNAL_D( Base::signal_f ), output, text );

				return;
			}
		}
	}
}

int Area::get_num( Cargo* cargo )
{

	for ( int i = 0; i < 9; i++ )
	{
		for ( int j = 0; j < squares[i].size(); j++ )
		{
			if ( squares[i][j] == cargo )
				return i + 1;
		}
	}

	return 0;
}

void Area::del_from_square( int sqr_num, Base* cargo )
{
	vector<Cargo*>& square = squares[sqr_num - 1];
	for ( auto it = square.begin(); it != square.end(); it++ )
	{

		if ( ( *it )->get_name() == cargo->get_name() )
		{
			square.erase( it );
			break;
		}
	}
}
