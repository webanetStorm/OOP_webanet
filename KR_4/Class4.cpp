#include "Class4.h"

cl_4::cl_4( Base* pParent, string _name ) :Base( pParent, _name )
{
	this->number = 4;
}

void cl_4::signal_f( string& msg )
{
	cout << endl << "Signal from " << this->get_path();
	msg += " (class: 4)";
}

void cl_4::handler_f( string msg )
{
	cout << endl << "Signal to " << get_path() << " Text:  " << msg;
}