#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


#define SIGNAL_D( signal_f ) ( TYPE_SIGNAL )( &signal_f )
#define HANDLER_D( handler_f ) ( TYPE_HANDLER )( &handler_f )

using namespace std;
class Base;

typedef void ( Base::*TYPE_SIGNAL ) ( string& message );
typedef void ( Base::*TYPE_HANDLER ) ( string message );


struct Connection
{

	TYPE_SIGNAL pSignal;
	TYPE_HANDLER p_handler;
	Base* p_target;
};


class Base
{

private:

	string _name;

	Base* pParent;

	vector<Base*> pChilds;

	int _readiness = 1;
	
	vector<Connection*> _connections;


public:

	Base( Base* pParent, string _name = "Base Object" );
	bool set_name( string s_new_name );
	string get_name();
	Base* get_head();
	void print_tree( string delay = "" );
	Base* get_sub_obj( string _name );
	~Base();
	int count( string name );
	Base* search_by_name( string name );
	Base* search_cur( string name );
	Base* search_from_root( string name );
	void set_ready( int s_new_ready );
	void get_ready( string name );
	void print_ready( string delay = "" );
	bool change_head_obj( Base* new_head_obj );
	void delete_subordinate_obj( string name );
	Base* find_obj_by_coord( string s_object_path );
	void print_from_current( int n = 0 );
	void set_connection( TYPE_SIGNAL pSignal, Base* p_target, TYPE_HANDLER p_handler );
	void delete_connection( TYPE_SIGNAL pSignal, Base* p_target, TYPE_HANDLER p_handler );
	void emit_signal( TYPE_SIGNAL pSignal, string massege );
	string get_path();
	int number = 1;
	typedef void ( Base::* TYPE_SIGNAL )( string& );
	typedef void ( Base::* TYPE_HANDLER )( string );
	void setState( int state );
	void delete_links( Base* targ );
	Base* get_root();

};
