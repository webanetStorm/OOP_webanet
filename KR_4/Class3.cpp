#include "Class3.h"

cl_3::cl_3( Base* pParent, string _name ) :Base( pParent, _name )
{
	this->number = 3;
}

void cl_3::signal_f( string& msg )
{
	cout << endl << "Signal from " << this->get_path();
	msg += " (class: 3)";
}

void cl_3::handler_f( string msg )
{
	cout << endl << "Signal to " << get_path() << " Text:  " << msg;
}