#include "Input.h"


Input::Input( Base* parent, string name ) : Base( parent, name )
{
}

void Input::Handler( string command )
{
	string text;

	getline( cin, text );

	this->EmitSignal( SIGNAL_D( Base::Signal ), this->GetParent(), text );
}
