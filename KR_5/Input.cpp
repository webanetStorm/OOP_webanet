#include "Input.h"
#include "Cargo.h"
#include "Area.h"

#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

Input::Input( Base* parent, string name ) : Base( parent, name )
{
}

void Input::handler_f( string command )
{
	init_data();
}

void Input::init_data()
{
	string text;
	getline( cin, text );
	emit_signal( SIGNAL_D( Base::signal_f ), get_parent(), text );
}
