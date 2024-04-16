#include "Application.h"
#include <iostream>


Application::Application( Base* pParentObject ) : Base( pParentObject ) {}

void Application::BuildTreeObjects()
{
	Base *pParentObject = this;
	string parentPath, childName;
	int classNumber;



	cin >> parentPath;
	this->SetObjectName( parentPath );


	while ( true )
	{

		cin >> parentPath;

		if ( parentPath == "endtree" )
			break;


		cin >> childName >> classNumber;

		pParentObject = this->FindObjectByPath( parentPath );

		if ( pParentObject && pParentObject->GetChildByName( childName ) == nullptr )
		{
			switch ( classNumber )
			{
				case 2:
					new Class2( pParentObject, childName );
					break;
				case 3:
					new Class3( pParentObject, childName );
					break;
				case 4:
					new Class4( pParentObject, childName );
					break;
				case 5:
					new Class5( pParentObject, childName );
					break;
				case 6:
					new Class6( pParentObject, childName );
					break;
			}
		}

	}

	

	cout << "Object tree";
	this->DisplayHierarchy();
	cout << endl;

	
	Base *pCurrentObject = this, *pObj = this;
	string command, parameter;

	while ( cin >> command, command != "END" )
	{

		cin >> parameter;

		pObj = pCurrentObject->FindObjectByPath( parameter );


		if ( command == "SET" )
		{
			if ( pObj )
			{
				pCurrentObject = pObj;
				cout << "Object is set: " << pCurrentObject->GetObjectName() << endl;
			}
			else
			{
				cout << "The object was not found at the specified coordinate: " << parameter << endl;
			}
		}
		else if ( command == "FIND" )
		{
			pObj
				? cout << parameter << "     Object name: " << pObj->GetObjectName() << endl
				: cout << parameter << "     Object is not found" << endl;
		}
		else if ( command == "MOVE" )
		{
			if ( pObj )
			{
				if ( pCurrentObject->SetNewParent( pObj ) )
					cout << "New head object: " << pObj->GetObjectName() << endl;
				else if ( pObj->GetChildByName( pCurrentObject->GetObjectName() ) )
					cout << parameter << "     Dubbing the names of subordinate objects" << endl;
				else
					cout << parameter << "     Redefining the head object failed" << endl;
			}
			else
			{
				cout << parameter << "     Head object is not found" << endl;
			}
		}
		else if ( command == "DELETE" )
		{
			if ( pObj )
			{
				pParentObject = pObj->GetParentObject();

				if ( pParentObject )
				{
					string fullPath = pObj->GetObjectName();
					Base* pCurrent = pObj->GetParentObject();

					while ( pCurrent != this )
					{
						fullPath = pCurrent->GetObjectName() + '/' + fullPath;
						pCurrent = pCurrent->GetParentObject();
					}

					pParentObject->DeleteChildByName( pObj->GetObjectName() );
					cout << "The object /" << fullPath << " has been deleted" << endl;
				}
			}
		}

	}
}

int Application::ExecApp()
{
	cout << "Current object hierarchy tree";

	this->DisplayHierarchy();

	return 0;
}
