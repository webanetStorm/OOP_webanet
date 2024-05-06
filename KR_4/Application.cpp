#include <iostream>
#include <stack>
#include "Application.h"

using namespace std;


Application::Application( Base* pParentObject ) : Base( pParentObject )
{
}

void Application::BuildTreeObjects()
{
	Base *pParentObject, *pLastCreatedObject = this;
	string parentName, childName;
	int classNumber;

	cin >> childName;
	this->SetObjectName( childName );


	while ( cin >> parentName, parentName != "endtree" )
	{

		cin >> childName >> classNumber;
		pParentObject = pLastCreatedObject->FindObjectByPath( parentName );

		if ( pParentObject )
		{
			switch ( classNumber )
			{
				case 1:
					pLastCreatedObject = new Class1( pParentObject, childName );
					break;
				case 2:
					pLastCreatedObject = new Class2( pParentObject, childName );
					break;
				case 3:
					pLastCreatedObject = new Class3( pParentObject, childName );
					break;
				case 4:
					pLastCreatedObject = new Class4( pParentObject, childName );
					break;
				case 5:
					pLastCreatedObject = new Class5( pParentObject, childName );
					break;
				case 6:
					pLastCreatedObject = new Class6( pParentObject, childName );
					break;
			}
		}
		else
		{
			cout << "Object tree";
			this->DisplayHierarchy();
			cout << endl << "The head object " << parentName << " is not found";

			exit( 1 );
		}

	}
}

int Application::ExecApp()
{
	cout << "Object tree";

	this->DisplayHierarchy();



	Base *pSender, *pReceiver;
	string senderPath, receiverPath, line, command, path, text;

	vector<TYPE_SIGNAL> SIGNALS_LIST =
	{
		SIGNAL_D( Class1::Signal ),
		SIGNAL_D( Class2::Signal ),
		SIGNAL_D( Class3::Signal ),
		SIGNAL_D( Class4::Signal ),
		SIGNAL_D( Class5::Signal ),
		SIGNAL_D( Class6::Signal )
	};

	vector<TYPE_HANDLER> HANDLERS_LIST =
	{
		HANDLER_D( Class1::Handler ),
		HANDLER_D( Class2::Handler ),
		HANDLER_D( Class3::Handler ),
		HANDLER_D( Class4::Handler ),
		HANDLER_D( Class5::Handler ),
		HANDLER_D( Class6::Handler )
	};



	while ( cin >> senderPath, senderPath != "end_of_connections" )
	{
		cin >> receiverPath;

		pSender = this->FindObjectByPath( senderPath );
		pReceiver = this->FindObjectByPath( receiverPath );

		if ( pSender and pReceiver )
			pSender->SetConnection( SIGNALS_LIST[pSender->ClassNumber - 1], pReceiver, HANDLERS_LIST[pReceiver->ClassNumber - 1] );
	}


	while ( cin >> line )
	{

		command = line.substr( 0, line.find( ' ' ) );
		line = line.substr( line.find( ' ' ) + 1, line.size() - 1 );
		path = line.substr( 0, line.find( ' ' ) );
		text = line.substr( line.find( ' ' ) + 1 );

		if ( command == "END" )
			break;
		if ( line == "" )
			continue;


		Base* pSender = this->FindObjectByPath( path );

		if ( !pSender )
		{
			cout << endl << "Object " << path << " not found";
			continue;
		}

		if ( command == "EMIT" )
		{
			pSender->EmitSignal( SIGNALS_LIST[pSender->ClassNumber - 1], text );
		}
		else if ( command == "SET_CONNECT" )
		{
			Base* pReceiver = this->FindObjectByPath( text );

			if ( !pReceiver )
				cout << endl << "Handler object " << text << " not found";
			else
				pSender->SetConnection( SIGNALS_LIST[pSender->ClassNumber - 1], pReceiver, HANDLERS_LIST[pReceiver->ClassNumber - 1] );
		}
		else if ( command == "DELETE_CONNECT" )
		{
			Base* pReceiver = this->FindObjectByPath( text );

			if ( !pReceiver )
				cout << endl << "Handler object " << text << " not found";
			else
				pSender->DeleteConnection( SIGNALS_LIST[pSender->ClassNumber - 1], pReceiver, HANDLERS_LIST[pReceiver->ClassNumber - 1] );
		}
		else if ( command == "SET_CONDITION" )
		{
			pSender->SetReadiness( stoi( text ) );
		}

	}


	return 0;
}
