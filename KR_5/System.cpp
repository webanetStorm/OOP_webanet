#include "System.h"
#include <sstream>


System::System( Base* pParent ) : Base( pParent )
{
}

void System::BuildTreeObjects()
{
	this->SetName( "System" );

	new SystemInput( this, "SystemInput" );
	new CraneController( this, "CraneController" );
	new CargoPlatform( this, "P1" );
	new CargoPlatform( this, "P2" );
	new CargoPlatform( this, "P3" );
	new ConstructionFloor( this, "ConstructionFloor" );
	// new Cargo( this, 4, 4, 4, "Cargo" );
	new InformationDisplay( this, "InformationDisplay" );


	string input;
	int houseNumber, houseLength, houseWidth, floor;

	cin >> houseLength >> houseWidth >> houseNumber;

	while ( getline( cin, input ) && input != "End of cargos" )
	{

		if ( input.empty() ) 
			continue;


		istringstream iss( input );
		int platformNumber, squareNumber;
		string cargoId;
		double length, width, height;

		iss >> platformNumber >> squareNumber >> cargoId >> length >> width >> height;

		string platformName = "P" + to_string( platformNumber );
		new Cargo( this->GetChildByName( platformName ), length, width, height, cargoId );

	}

}

int System::ExecApp()
{
	this->Display();


	return 0;
}
