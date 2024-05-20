#ifndef __CONTROLLER__H
#define __CONTROLLER__H

#include "Base.h"

class Controller : public Base
{
public:
	Controller( Base* parent, string name = "Controller object" );
	void find_cargo( string id );
	void work( string id = 0 );
	void crane_info();
	virtual void handler_f( string command );

private:
	int n = 0, m = 0, E = 0;
	int angle = 0;
	int d = 1;

	string carg_id = "";
	int floor_sqr_num;
};

#endif
