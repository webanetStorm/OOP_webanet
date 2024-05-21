#include "Input.h"


Input::Input( Base* pParent, string name ) : Base( pParent, name )
{
}

void Input::Handler( string command )
{
	string text;

	getline( cin, text );

	this->EmitSignal( SIGNAL_D( Base::Signal ), this->GetParent(), text );
}
