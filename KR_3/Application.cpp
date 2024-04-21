#include <iostream>
#include <stack>
#include "Application.h"

using namespace std;


Application::Application( Base* pParentObject ) : Base( pParentObject )
{
}

int Application::ExecApp()
{
	string command, parameter;
	Base *pCurrentObject = this, *pObj = nullptr;
	stack<string> pathStack;

	this->DisplayHierarchy();


	while ( cin >> command, command != "END" )
	{

		cin >> parameter;

		pObj = pCurrentObject->FindObjectByPath( parameter );


		if ( command == "SET" )
		{
			if ( pObj )
			{
				pCurrentObject = pObj;
				cout << endl << "Object is set: " << pCurrentObject->GetObjectName();
			}
			else
				cout << endl << "The object was not found at the specified coordinate: " << parameter;
		}
		else if ( command == "FIND" )
		{
			pObj
				? cout << endl << parameter << "     Object name: " << pObj->GetObjectName()
				: cout << endl << parameter << "     Object is not found";
		}
		else if ( command == "MOVE" )
		{
			if ( pCurrentObject->SetNewParent( pObj ) )
				cout << endl << "New head object: " << pObj->GetObjectName();
			else if ( !pObj )
				cout << endl << parameter << "     Head object is not found";
			else if ( pObj->GetChildByName( pCurrentObject->GetObjectName() ) )
				cout << endl << parameter << "     Dubbing the names of subordinate objects";
			else
				cout << endl << parameter << "     Redefining the head object failed";
		}
		else if ( command == "DELETE" )
		{
			pObj = pCurrentObject->GetChildByName( parameter );

			if ( pObj )
			{
				while ( pObj->GetParentObject() )
				{
					pathStack.push( pObj->GetObjectName() );
					pObj = pObj->GetParentObject();
				}

				pCurrentObject->DeleteChildByName( parameter );
				cout << endl << "The object ";

				while ( !pathStack.empty() )
				{
					cout << '/' << pathStack.top();
					pathStack.pop();
				}

				cout << " has been deleted";
			}
		}
	}


	cout << endl << "Current object hierarchy tree";

	this->DisplayHierarchy();


	return 0;
}

void Application::BuildTreeObjects()
{
	Base *pParentObject, *pLastCreatedObject = this;
	string path, childName;
	int classNumber;

	cout << "Object tree";
	cin >> childName;
	this->SetObjectName( childName );


	while ( cin >> path, path != "endtree" )
	{

		cin >> childName >> classNumber;
		pParentObject = pLastCreatedObject->FindObjectByPath( path );


		if ( !pParentObject )
		{
			this->DisplayHierarchy();
			cout << endl << "The head object " << path << " is not found";

			return;
		}


		if ( pParentObject->GetChildByName( childName ) )
		{
			cout << endl << path << "     Dubbing the names of subordinate objects";
		}
		else
		{
			switch ( classNumber )
			{
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

	}
}
