#ifndef __AREA__H
#define __AREA__H


#include "Base.h"
#include "Cargo.h"


class Area : public Base
{

public:

	int CountSqr = 0;

	vector<vector<Cargo*>> Squares;


	Area( Base* pParent, string name );

	void SetCountSqr( int value );

	void CheckCargos( string text );

	void GetCondition( string id );

	int GetNumber( Cargo* cargo );

	void DeleteFromSquare( int sqrNumber, Base* cargo );

	virtual void Handler( string command );

};


#endif
