#include "Application.h"
#include <iostream>


Application::Application( Base* pParentObject ) : Base( pParentObject ) {}

void Application::BuildTreeObjects()
{
	Base *pParentObject = this, *pCurrentObject = this, *pObj;
	string parentPath, childName, command, parameter;
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

	while ( cin >> command )
	{
		if ( command == "SET" )
		{
			cin >> parameter;
			Base* obj = this->FindObjectByPath( parameter );
			if ( obj )
			{
				pCurrentObject = obj;
				cout << "Object is set: " << obj->GetObjectName() << endl;
			}
			else
			{
				cout << "The object was not found at the specified coordinate: " << parameter << endl;
			}
		}
		else if ( command == "FIND" )
		{
			cin >> parameter;
			Base* obj = pCurrentObject->FindObjectByPath( parameter );
			if ( obj )
			{
				cout << parameter << "     Object name: " << obj->GetObjectName() << endl;
			}
			else
			{
				cout << parameter << "     Object is not found" << endl;
			}
		}
		else if ( command == "MOVE" )
		{
			cin >> parameter;
			Base* newParent = pCurrentObject->FindObjectByPath( parameter );
			if ( pCurrentObject->SetNewParent( newParent ) )
			{
				cout << "New head object: " << newParent->GetObjectName() << endl;
			}
			else
			{
				cout << "Redefining the head object failed" << endl;
			}
		}
		else if ( command == "DELETE" )
		{
			cin >> parameter;
			pCurrentObject->DeleteChildByName( parameter );
			cout << "The object " << parameter << " has been deleted" << endl;
		}
		else if ( command == "END" )
		{
			break; // Завершение программы
		}
	}
}

int Application::ExecApp()
{
	cout << "Object tree";

	this->DisplayHierarchy();


	return 0;
}
