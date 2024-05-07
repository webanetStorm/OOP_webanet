#include "Class2.h"

cl_2::cl_2( Base* pParent, string _name ) :Base( pParent, _name )
{
	this->number = 2;
}

void cl_2::signal_f( string& msg )
{
	cout << endl << "Signal from " << this->get_path();
	msg += " (class: 2)";
}

void cl_2::handler_f( string msg )
{
	cout << endl << "Signal to " << get_path() << " Text:  " << msg;
}