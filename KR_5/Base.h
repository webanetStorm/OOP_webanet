#ifndef __BASE__H
#define __BASE__H

#include <vector>
#include <string>
using namespace std;

class Base;
typedef void ( Base::*TYPE_SIGNAL ) ( string & );
typedef void ( Base::*TYPE_HANDLER ) ( string );

#define SIGNAL_D(signal_f) (TYPE_SIGNAL) (& signal_f)
#define HANDLER_D(handler_f) (TYPE_HANDLER) (& handler_f)

class Base
{
public:
	Base( Base* parent, string name = "Base_object" );
	bool set_name( string new_name );
	string get_name();
	Base* get_parent();
	void print_tree( int step = 1 );
	Base* get_child( string child_name );
	Base* find_in_tree( string obj_name );
	void set_state( int state );
	int get_state();
	void print_tree_states( int step = 1 );

	Base* find_by_coords( string obj_coords );
	Base* find( string obj_name );
	Base* find_with_count( string obj_name, int& count );
	void del_child( string obj_name );
	~Base();
	bool is_child( Base* obj );
	bool set_parent( Base* obj );
	void add_child( Base* obj );

	// new
	string get_abs_coords();
	void set_connect( TYPE_SIGNAL signal, Base* obj, TYPE_HANDLER handler );
	void del_connect( TYPE_SIGNAL signal, Base* obj, TYPE_HANDLER handler );
	void emit_signal( TYPE_SIGNAL signal, Base* obj, string& command );
	virtual void signal_f( string& command );
	virtual void handler_f( string command );

	vector<string> get_words( string str );

private:
	string name;
	Base* parent;
	vector<Base*> children;
	int state = 0;

	//new
	struct Connection
	{
		TYPE_SIGNAL signal;
		Base* obj;
		TYPE_HANDLER handler;
	};

	vector<Connection*> connections;
};

#endif
