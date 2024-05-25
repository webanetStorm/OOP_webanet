#include "Area.h"


Area::Area( Base* pParent, string name ) : Base( pParent, name )
{
}

void Area::Handler( string command )
{
	if ( command.find( "Condition of the cargo area" ) != string::npos )
		this->CheckCargos( command + " --" );
	else if ( command.find( "Cargo condition" ) != string::npos )
		this->GetCondition( this->Explode( command )[2] );
}

void Area::SetCountSquares( int value )
{
	this->Squares = vector<vector<Cargo*>>( value );
}

void Area::CheckCargos( string text )
{
	for ( int i = 0; i < this->Squares.size(); i++ )
	{
		if ( !this->Squares[i].empty() )
		{
			text += " s " + to_string( i + 1 ) + ":";

			for ( auto it = this->Squares[i].rbegin(); it != this->Squares[i].rend(); it++ )
				text += " " + ( *it )->GetName();
		}
	}

	this->EmitSignal( SIGNAL_D( Base::Signal ), this->GetParent()->GetChildByName( "Output object" ), text );

}

void Area::GetCondition( string id )
{
	string text = "Cargo condition " + id;

	for ( int i = 0; i < Squares.size(); i++ )
	{
		if ( Squares[i].size() == 0 )
			continue;

		for ( auto cargo : Squares[i] )
		{
			if ( cargo->GetName() == id )
			{
				string name = GetName();

				if ( name.find( "Cargo area" ) != string::npos )
					text += ": in area " + name.substr( name.size() - 1 ) + ", square " + to_string( i + 1 );
				else if ( name.find( "Floor area" ) != string::npos )
					text += ": in floor square " + to_string( i + 1 );


				this->EmitSignal( SIGNAL_D( Base::Signal ), this->GetParent()->GetChildByName( "Output object" ), text );

				return;
			}
		}
	}
}

int Area::GetNumber( Cargo* cargo )
{
	for ( int i = 0; i < 9; i++ )
		for ( int j = 0; j < Squares[i].size(); j++ )
			if ( Squares[i][j] == cargo )
				return i + 1;

	return 0;
}

void Area::DeleteFromSquare( int sqrNumber, Base* cargo )
{
	vector<Cargo*>& square = Squares[sqrNumber - 1];

	for ( auto it = square.begin(); it != square.end(); it++ )
	{
		if ( ( *it )->GetName() == cargo->GetName() )
		{
			square.erase( it );
			break;
		}
	}
}
