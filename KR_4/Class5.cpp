#include "Class5.h"

cl_5::cl_5( Base* pParent, string _name ) :Base( pParent, _name )
{
	this->number = 5;
}

void cl_5::signal_f( string& msg )
{
	cout << endl << "Signal from " << this->get_path();
	msg += " (class: 5)";
}

void cl_5::handler_f( string msg )
{
	cout << endl << "Signal to " << get_path() << " Text:  " << msg;
}