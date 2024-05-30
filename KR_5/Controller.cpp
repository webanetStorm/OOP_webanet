#define _USE_MATH_DEFINES
#include "Controller.h"
#include "Area.h"
#include "Output.h"
#include "Cargo.h"
#include <cmath>


Controller::Controller( Base* pParent, string name ) : Base( pParent, name )
{
}

void Controller::Handler( string command )
{
	vector<string> commands = this->Explode( command );

	if ( command.find( "Submit the cargo" ) != string::npos )
	{
		this->_squareNumber = stoi( commands[4] );
		this->FindCargo( commands[3] );
	}
	else if ( command == "Condition of the tower crane" )
	{
		string text = "Tower crane " + to_string( this->_boomAngle ) + "  " + to_string( this->_boomLength );

		this->EmitSignal( SIGNAL_D( Base::Signal ), this->GetParent()->GetChildByName( "Output object" ), text );
	}
	else if ( command == "" )
	{
		if ( this->GetReadiness() != 1 )
			this->Work( this->_cargoId );
	}
	else
	{
		this->_n = stoi( commands[0] );
		this->_m = stoi( commands[1] );
		this->_floorNumber = stoi( commands[2] );
	}
}

void Controller::FindCargo( string id )
{
	auto root = this->GetParent(), cargo = root->FindOnBranch( id );
	string text;

	if ( !cargo )
	{
		text = "Cargo " + id + " not found";
	}
	else
	{
		auto parent = cargo->GetParent();

		if ( parent == this )
		{
			text = "The cargo " + id + " is located on the hook of the tower crane";
		}
		else if ( parent->GetName() == "Floor area" )
		{
			text = "The cargo " + id + " is located on the floor";
		}
		else
		{
			Area *area1 = (Area*)root->GetChildByName( "Cargo area 1" ), *area2 = (Area*)root->GetChildByName( "Cargo area 2" ), *area3 = (Area*)root->GetChildByName( "Cargo area 3" );
			bool isInEnd = false;

			for ( int i = 0; i < 9; i++ )
			{
				if ( ( area1->Squares[i].size() != 0 ) && ( area1->Squares[i].back()->GetName() == id ) || ( area2->Squares[i].size() != 0 ) && ( area2->Squares[i].back()->GetName() == id ) || ( area3->Squares[i].size() != 0 ) && ( area3->Squares[i].back()->GetName() == id ) )
				{
					isInEnd = true;
					break;
				}
			}

			if ( !isInEnd )
				text = "The cargo " + id + " is not available";
		}
	}

	text != "" ? this->EmitSignal( SIGNAL_D( Base::Signal ), root->GetChildByName( "Output object" ), text ) : this->Work( id );
}

void Controller::Work( string id )
{
	Cargo* cargo = (Cargo*)this->GetParent()->FindOnBranch( id );
	Area* area = (Area*)( cargo->GetParent() );

	switch ( this->GetReadiness() )
	{
		case 1:
		{
			this->_cargoId = id;

			int squareNumber = area->GetNumber( cargo ), x, y;

			switch ( area->GetName().back() - '0' )
			{
				case 1:
					x = 16 - ( squareNumber - 1 ) % 3 * 4;
					y = 2 + ( squareNumber - 1 ) / 3 * 4;
					this->_boomAngle = 180 + atan2( y, x ) * 180 / M_PI;
					break;
				case 2:
					x = -4 + ( squareNumber - 1 ) % 3 * 4;
					y = 14 + ( squareNumber - 1 ) / 3 * 4;
					this->_boomAngle = 180 + atan2( y, x ) * 180 / M_PI + ( 90 - atan2( y, x ) * 180 / M_PI ) * ( ( squareNumber - 1 ) % 3 );
					break;
				case 3:
					x = 8 + ( squareNumber - 1 ) % 3 * 4;
					y = 2 + ( squareNumber - 1 ) / 3 * 4;
					this->_boomAngle = 360 - atan2( y, x ) * 180 / M_PI;
					break;
			}
			this->_boomLength = sqrt( x * x + y * y );

			break;
		}
		case 2:
		{
			cargo->SetNewParent( this );
			area->DeleteFromSquare( area->GetNumber( cargo ), cargo );

			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			int x = 2 - this->_m / 2 + ( this->_squareNumber - 1 ) % ( this->_m / 4 ) * 4, y = 2 + this->_n - ( this->_squareNumber - 1 ) / ( this->_m / 4 ) * 4;

			if ( x == 0 )
				this->_boomAngle = 90;
			else
				this->_boomAngle = atan2( y, x ) * 180 / M_PI;

			if ( this->_boomAngle == 155 )
				this->_boomAngle++;

			this->_boomLength = sqrt( x * x + y * y );
			break;
		}
		case 5:
		{
			Area* areaFloor = (Area*)( this->GetParent()->GetChildByName( "Floor area" ) );
			cargo->SetNewParent( areaFloor );
			areaFloor->Squares[this->_squareNumber - 1].push_back( cargo );

			this->_boomAngle = 0;
			break;
		}
		case 6:
		{
			this->_boomAngle = 0;
			break;
		}
	}

	this->SetReadiness( this->GetReadiness() + 1 );

	if ( this->GetReadiness() > 6 )
		this->SetReadiness( 1 );
}
