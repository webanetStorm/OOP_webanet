#include "Class1.h"

cl_1::cl_1( Base* pParent, string _name ) :Base( pParent, _name )
{
	this->number = 1;
}

void cl_1::signal_f( string& msg )
{
	cout << endl << "Signal from " << this->get_path();
	msg += " (class: 1)";
}

void cl_1::handler_f( string msg )
{
	cout << endl << "Signal to " << get_path() << " Text:  " << msg;
}