#ifndef __AREA__H
#define __AREA__H

#include "Base.h"
#include "Cargo.h"

class Area : public Base
{
public:
	Area( Base* parent, string name );
	void set_count_sqr( int n );
	void check_cargos( string text );
	void get_condition( string id );
	int get_num( Cargo* cargo );
	void del_from_square( int sqr_num, Base* cargo );
	virtual void handler_f( string command );

	int count_sqr = 0;
	vector<vector<Cargo*>> squares;
};

#endif
