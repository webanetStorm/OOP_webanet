#include "System.h"


System::System( Base* pParent, string name ) : Base( nullptr, name )
{
}

void System::Signal( string& command )
{
	Base::Signal( command );
}

void System::Handler( string command )
{
	this->_data = command;
	Base::Handler( command );
}

void System::BuildTreeObjects()
{
	Base* input = new Input( this );
	auto controller = new Controller( this );
	auto area1 = new Area( this, "Cargo area 1" );
	auto area2 = new Area( this, "Cargo area 2" );
	auto area3 = new Area( this, "Cargo area 3" );
	auto areaFloor = new AreaFloor( this, "Floor area" );
	auto output = new Output( this );

	area1->SetCountSqr( 9 );
	area2->SetCountSqr( 9 );
	area3->SetCountSqr( 9 );

	input->SetReadiness( 1 );
	controller->SetReadiness( 1 );
	area1->SetReadiness( 1 );
	area2->SetReadiness( 1 );
	area3->SetReadiness( 1 );
	areaFloor->SetReadiness( 1 );
	output->SetReadiness( 1 );

	this->SetConnection( SIGNAL_D( Base::Signal ), input, HANDLER_D( Base::Handler ) );
	this->SetConnection( SIGNAL_D( Base::Signal ), controller, HANDLER_D( Base::Handler ) );
	this->SetConnection( SIGNAL_D( Base::Signal ), area1, HANDLER_D( Base::Handler ) );
	this->SetConnection( SIGNAL_D( Base::Signal ), area2, HANDLER_D( Base::Handler ) );
	this->SetConnection( SIGNAL_D( Base::Signal ), area3, HANDLER_D( Base::Handler ) );
	this->SetConnection( SIGNAL_D( Base::Signal ), areaFloor, HANDLER_D( Base::Handler ) );
	this->SetConnection( SIGNAL_D( Base::Signal ), output, HANDLER_D( Base::Handler ) );

	controller->SetConnection( SIGNAL_D( Base::Signal ), output, HANDLER_D( Base::Handler ) );
	area1->SetConnection( SIGNAL_D( Base::Signal ), output, HANDLER_D( Base::Handler ) );
	area2->SetConnection( SIGNAL_D( Base::Signal ), output, HANDLER_D( Base::Handler ) );
	area3->SetConnection( SIGNAL_D( Base::Signal ), output, HANDLER_D( Base::Handler ) );
	areaFloor->SetConnection( SIGNAL_D( Base::Signal ), output, HANDLER_D( Base::Handler ) );
	input->SetConnection( SIGNAL_D( Base::Signal ), this, HANDLER_D( Base::Handler ) );


	bool isFirst = true;

	while ( true )
	{
		this->EmitSignal( SIGNAL_D( Base::Signal ), input, this->_data );

		if ( this->_data == "End of cargos" )
			break;

		if ( isFirst )
		{
			this->EmitSignal( SIGNAL_D( Base::Signal ), controller, this->_data );
			this->EmitSignal( SIGNAL_D( Base::Signal ), areaFloor, this->_data );

			isFirst = false;
		}
		else
		{
			vector<string> commands = Explode( this->_data );
			Area* area = nullptr;

			switch ( stoi( commands[0] ) )
			{
				case 1:
					area = (Area*)area1;
					break;
				case 2:
					area = (Area*)area2;
					break;
				case 3:
					area = (Area*)area3;
					break;
			}

			auto cargo = new Cargo( area, commands[2], stof( commands[3] ), stof( commands[4] ), stof( commands[5] ) );
			cargo->SetReadiness( 1 );
			area->Squares[stoi( commands[1] ) - 1].push_back( cargo );
		}
	}
}


int System::ExecApp()
{
	Input* input = (Input*)( this->GetChildByName( "Input object" ) );
	Controller* controller = (Controller*)( this->GetChildByName( "Controller object" ) );
	Area* area1 = (Area*)( this->GetChildByName( "Cargo area 1" ) );
	Area* area2 = (Area*)( this->GetChildByName( "Cargo area 2" ) );
	Area* area3 = (Area*)( this->GetChildByName( "Cargo area 3" ) );
	AreaFloor* areaFloor = (AreaFloor*)( this->GetChildByName( "Floor area" ) );
	Output* output = (Output*)( this->GetChildByName( "Output object" ) );


	this->_data = "Ready to work";
	this->EmitSignal( SIGNAL_D( Base::Signal ), output, this->_data );

	while ( true )
	{
		this->EmitSignal( SIGNAL_D( Base::Signal ), input, this->_data );

		if ( this->_data == "Turn off the system" )
		{
			this->EmitSignal( SIGNAL_D( Base::Signal ), output, this->_data );
			break;
		}


		if ( this->_data == "SHOWTREE" )
		{
			cout << "\nObject tree";
			this->DisplayWithReadiness();
		}
		else if ( this->_data.find( "Submit the cargo" ) != string::npos )
		{
			this->EmitSignal( SIGNAL_D( Base::Signal ), controller, this->_data );
			continue;
		}
		else if ( this->_data.find( "Condition of the cargo area" ) != string::npos )
		{
			if ( this->_data.find( "1" ) != string::npos )
			{
				this->EmitSignal( SIGNAL_D( Base::Signal ), area1, this->_data );
			}
			else if ( this->_data.find( "2" ) != string::npos )
			{
				this->EmitSignal( SIGNAL_D( Base::Signal ), area2, this->_data );
			}
			else if ( this->_data.find( "3" ) != string::npos )
			{
				this->EmitSignal( SIGNAL_D( Base::Signal ), area3, this->_data );
			}
		}
		else if ( this->_data.find( "Cargo condition" ) != string::npos )
		{
			vector<string> commands = this->Explode( this->_data );
			string cargoId = commands[2];

			if ( area1->FindOnBranch( cargoId ) )
			{
				this->EmitSignal( SIGNAL_D( Base::Signal ), area1, this->_data );
			}
			else if ( area2->FindOnBranch( cargoId ) )
			{
				this->EmitSignal( SIGNAL_D( Base::Signal ), area2, this->_data );
			}
			else if ( area3->FindOnBranch( cargoId ) )
			{
				this->EmitSignal( SIGNAL_D( Base::Signal ), area3, this->_data );
			}
			else if ( areaFloor->FindOnBranch( cargoId ) )
			{
				this->EmitSignal( SIGNAL_D( Base::Signal ), areaFloor, this->_data );
			}
			else if ( controller->FindOnBranch( cargoId ) )
			{
				this->_data += ": in hook";
				this->EmitSignal( SIGNAL_D( Base::Signal ), output, this->_data );
			}
			else
			{
				this->_data = "Cargo " + cargoId + " not found";
				this->EmitSignal( SIGNAL_D( Base::Signal ), output, this->_data );
			}
		}
		else if ( this->_data.find( "Condition of the tower crane" ) != string::npos )
		{
			this->EmitSignal( SIGNAL_D( Base::Signal ), controller, this->_data );
		}
		else if ( this->_data.find( "Floor condition" ) != string::npos )
		{
			this->EmitSignal( SIGNAL_D( Base::Signal ), areaFloor, this->_data );
		}

		this->_data = "";
		this->EmitSignal( SIGNAL_D( Base::Signal ), controller, this->_data );
	}


	return 0;
}
