#include "System.h"


System::System( Base* pParent ) : Base( pParent )
{
}

void System::BuildTreeObjects()
{
	Base *pParentObject = this, *pChildObject = nullptr;
	string parentName, childName;
	int classNumber;

	cin >> parentName;
	this->SetName( parentName );


	while ( cin >> parentName, parentName != "endtree" )
	{

		cin >> childName >> classNumber;

		if ( pParentObject )
		{
			pParentObject = this->FindObjectByPath( parentName );

			switch ( classNumber )
			{
				case 1:
					pChildObject = new SystemInput( pParentObject, childName );
					break;
				case 2:
					pChildObject = new CraneController( pParentObject, childName );
					break;
				case 3:
					pChildObject = new CargoPlatform( pParentObject, childName );
					break;
				case 4:
					pChildObject = new ConstructionFloor( pParentObject, childName );
					break;
				case 5:
					pChildObject = new Cargo( pParentObject, childName );
					break;
				case 6:
					pChildObject = new InformationDisplay( pParentObject, childName );
					break;
			}
		}
		else
		{
			cout << "Object tree";
			this->Display();
			cout << endl << "The head object " << parentName << " is not found";

			exit( 1 );
		}

	}
}

int System::ExecApp()
{
	cout << "Object tree";

	this->Display();



	Base *pSender, *pReceiver;
	string senderPath, receiverPath, line, command, path, text;


	vector<TYPE_SIGNAL> SIGNALS_LIST =
	{
		SIGNAL_D( SystemInput::SignalF ),
		SIGNAL_D( CraneController::SignalF ),
		SIGNAL_D( CargoPlatform::SignalF ),
		SIGNAL_D( ConstructionFloor::SignalF ),
		SIGNAL_D( Cargo::SignalF ),
		SIGNAL_D( InformationDisplay::SignalF )
	};
	vector<TYPE_HANDLER> HANDLERS_LIST =
	{
		HANDLER_D( SystemInput::HandlerF ),
		HANDLER_D( CraneController::HandlerF ),
		HANDLER_D( CargoPlatform::HandlerF ),
		HANDLER_D( ConstructionFloor::HandlerF ),
		HANDLER_D( Cargo::HandlerF ),
		HANDLER_D( InformationDisplay::HandlerF )
	};


	while ( cin >> senderPath, senderPath != "end_of_connections" )
	{
		cin >> receiverPath;

		pSender = this->FindObjectByPath( senderPath );
		pReceiver = this->FindObjectByPath( receiverPath );

		pSender->SetConnection( SIGNALS_LIST[pSender->ClassNumber - 1], pReceiver, HANDLERS_LIST[pReceiver->ClassNumber - 1] );
	}



	while ( getline( cin, line ) )
	{

		command = line.substr( 0, line.find( ' ' ) );
		line = line.substr( line.find( ' ' ) + 1, line.size() - 1 );
		path = line.substr( 0, line.find( ' ' ) );
		text = line.substr( line.find( ' ' ) + 1 );

		if ( command == "END" )
		{
			break;
		}
		if ( line == "" )
		{
			continue;
		}


		Base* pSender = this->FindObjectByPath( path );

		if ( pSender == nullptr )
		{
			cout << endl << "Object " << path << " not found";
			continue;
		}
		if ( command == "EMIT" )
		{
			pSender->EmitSignal( SIGNALS_LIST[pSender->ClassNumber - 1], text );
		}
		if ( command == "SET_CONNECT" )
		{
			Base* pReceiver = this->FindObjectByPath( text );

			if ( !pReceiver )
				cout << endl << "Handler object " << text << " not found";
			else
				pSender->SetConnection( SIGNALS_LIST[pSender->ClassNumber - 1], pReceiver, HANDLERS_LIST[pReceiver->ClassNumber - 1] );
		}
		if ( command == "DELETE_CONNECT" )
		{
			Base* pReceiver = this->FindObjectByPath( text );

			if ( !pReceiver )
				cout << endl << "Handler object " << text << " not found";
			else
				pSender->DeleteConnection( SIGNALS_LIST[pSender->ClassNumber - 1], pReceiver, HANDLERS_LIST[pReceiver->ClassNumber - 1] );
		}
		if ( command == "SET_CONDITION" )
		{
			pSender->SetReadiness( stoi( text ) );
		}

	}


	return 0;
}
