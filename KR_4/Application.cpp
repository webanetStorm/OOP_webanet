#include "Application.h"


Application::Application( Base* pParent ) : Base( pParent )
{
}

void Application::BuildTreeObjects()
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
					pChildObject = new Class1( pParentObject, childName );
					break;
				case 2:
					pChildObject = new Class2( pParentObject, childName );
					break;
				case 3:
					pChildObject = new Class3( pParentObject, childName );
					break;
				case 4:
					pChildObject = new Class4( pParentObject, childName );
					break;
				case 5:
					pChildObject = new Class5( pParentObject, childName );
					break;
				case 6:
					pChildObject = new Class6( pParentObject, childName );
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

int Application::ExecApp()
{
	cout << "Object tree";

	this->Display();



	Base *pSender, *pReceiver;
	string senderPath, receiverPath, line, command, path, text;


	vector<TYPE_SIGNAL> SIGNALS_LIST =
	{
		SIGNAL_D( Class1::SignalF ),
		SIGNAL_D( Class2::SignalF ),
		SIGNAL_D( Class3::SignalF ),
		SIGNAL_D( Class4::SignalF ),
		SIGNAL_D( Class5::SignalF ),
		SIGNAL_D( Class6::SignalF )
	};
	vector<TYPE_HANDLER> HANDLERS_LIST =
	{
		HANDLER_D( Class1::HandlerF ),
		HANDLER_D( Class2::HandlerF ),
		HANDLER_D( Class3::HandlerF ),
		HANDLER_D( Class4::HandlerF ),
		HANDLER_D( Class5::HandlerF ),
		HANDLER_D( Class6::HandlerF )
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
			TYPE_SIGNAL signal = SIGNALS_LIST[pSender->ClassNumber - 1];
			pSender->EmitSignal( signal, text );
		}
		if ( command == "SET_CONNECT" )
		{
			Base* pReceiver = this->FindObjectByPath( text );

			if ( !pReceiver )
				cout << endl << "Handler object " << text << " not found";

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
