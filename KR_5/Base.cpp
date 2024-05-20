#include "Base.h"

#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

Base::Base( Base* parent, string name )
{
	this->parent = parent;
	this->name = name;

	if ( parent )
	{
		parent->children.push_back( this );
	}
}

bool Base::set_name( string new_name )
{
	if ( parent )
	{
		for ( Base* child : parent->children )
		{
			if ( child->get_name() == new_name )
				return false;
		}
	}

	name = new_name;
	return true;
}

string Base::get_name()
{
	return name;
}

Base* Base::get_parent()
{
	return parent;
}

void Base::print_tree( int step )
{
	if ( children.empty() )
		return;

	if ( !get_parent() )
		cout << name;

	for ( Base* child : children )
	{
		cout << endl;
		for ( int i = 0; i < step; i++ )
			cout << "    ";
		cout << child->get_name();
		child->print_tree( step + 1 );
	}
}

Base* Base::get_child( string child_name )
{
	for ( Base* child : children )
	{
		if ( child->get_name() == child_name )
			return child;
	}

	return nullptr;
}

Base* Base::find_in_tree( string obj_name )
{
	if ( obj_name == get_name() )
		return this;

	for ( Base* child : children )
	{
		Base* obj = child->find_in_tree( obj_name );
		if ( obj ) return obj;
	}

	return nullptr;
}

void Base::set_state( int state )
{
	if ( state == 0 )
	{
		this->state = 0;
		for ( auto child : children )
		{
			child->set_state( 0 );
		}
	}
	else
	{
		auto obj = this->get_parent();

		while ( obj )
		{
			if ( obj->get_state() == 0 )
				return;

			obj = obj->get_parent();
		}
		this->state = state;
	}
}

int Base::get_state()
{
	return state;
}

void Base::print_tree_states( int step )
{
	if ( children.empty() )
		return;

	for ( Base* child : children )
	{
		cout << endl;

		for ( int i = 0; i < step; i++ )
			cout << "    ";

		if ( child->get_state() != 0 )
		{
			cout << child->get_name() << " is ready";
		}
		else
		{
			cout << child->get_name() << " is not ready";
		}

		child->print_tree_states( step + 1 );
	}
}

Base* Base::find_by_coords( string coords )
{
	if ( coords[0] == '/' )
	{
		Base* obj = this;

		while ( obj->get_parent() )
			obj = obj->get_parent();

		if ( coords.substr( 0, 2 ) == "//" )
			return obj->find( coords.substr( 2 ) );

		if ( coords == "/" ) return obj;
		return obj->find_by_coords( coords.substr( 1 ) );
	}
	else if ( coords[0] == '.' )
	{
		if ( coords == "." ) return this;

		return find( coords.substr( 1 ) );
	}
	else
	{
		int i = 0;
		while ( ( i < coords.length() ) && ( coords[i] != '/' ) ) i++;
		string obj_name = coords.substr( 0, i );

		auto obj = get_child( obj_name );
		if ( obj && coords.substr( i ) != "" )
			return obj->find_by_coords( coords.substr( i + 1 ) );
		return obj;
	}
}

Base* Base::find( string obj_name )
{
	int count = 0;
	auto found_obj = find_with_count( obj_name, count );

	if ( count > 1 ) return nullptr;
	return found_obj;
}

Base* Base::find_with_count( string obj_name, int& count )
{
	Base* found_obj = nullptr;

	if ( name == obj_name )
	{
		count++;
		found_obj = this;
	}

	for ( auto child : children )
	{
		auto obj = child->find_with_count( obj_name, count );
		if ( obj ) found_obj = obj;
	}

	return found_obj;
}

void Base::del_child( string obj_name )
{
	for ( auto iter = children.begin(); iter != children.end(); iter++ )
	{
		if ( ( *iter )->get_name() == obj_name )
		{
			children.erase( iter );
			break;
		}
	}
}

Base::~Base()
{
	for ( auto child : children )
		delete child;
}

bool Base::is_child( Base* obj )
{
	for ( auto child : children )
	{
		if ( child == obj )
			return true;

		if ( child->is_child( obj ) )
			return true;
	}
	return false;
}

bool Base::set_parent( Base* obj )
{
	if ( !get_parent() || obj->get_child( get_name() )
		|| !obj || is_child( obj ) )
		return false;

	get_parent()->del_child( name );
	obj->add_child( this );
	parent = obj;

	return true;
}

void Base::add_child( Base* obj )
{
	children.push_back( obj );
}

string Base::get_abs_coords()
{
	if ( !get_parent() ) return "/";

	Base* obj = this;
	string path = "";

	while ( obj->get_parent() )
	{
		path = "/" + obj->get_name() + path;
		obj = obj->get_parent();
	}

	return path;
}

void Base::set_connect( TYPE_SIGNAL signal, Base* obj, TYPE_HANDLER handler )
{
	Connection* p_val;

	for ( unsigned int i = 0; i < connections.size(); i++ )
	{
		if ( connections[i]->signal == signal &&
			connections[i]->obj == obj &&
			connections[i]->handler == handler )
		{
			return;
		}
	}

	p_val = new Connection();

	p_val->signal = signal;
	p_val->obj = obj;
	p_val->handler = handler;

	connections.push_back( p_val );
}


void Base::del_connect( TYPE_SIGNAL signal, Base* obj, TYPE_HANDLER handler )
{
	for ( auto it = connections.begin(); it != connections.end(); it++ )
	{
		if ( ( *it )->signal == signal &&
			( *it )->obj == obj &&
			( *it )->handler == handler )
		{
			connections.erase( it );
			break;
		}
	}
}

void Base::emit_signal( TYPE_SIGNAL signal, Base* object, string& command )
{
	if ( !get_state() ) return;

	TYPE_HANDLER handler;
	Base* obj;

	( this->*signal ) ( command );

	for ( auto connection : connections )
	{

		if ( connection->signal == signal && connection->obj->get_state() )
		{

			if ( connection->obj->get_name() == object->get_name() )
			{
				handler = connection->handler;
				obj = connection->obj;

				( obj->*handler ) ( command );

				break;
			}
		}
	}
}

void Base::signal_f( string& command )
{
	//cout << endl << "Signal from " << this->get_abs_coords();
}

void Base::handler_f( string command )
{
	//cout << endl << "Signal to " << this->get_abs_coords() << " Text: " << command;
}

vector<string> Base::get_words( string str )
{
	vector<string> words;

	istringstream ist( str );
	for ( string word; ist >> word;)
	{
		words.push_back( word );
	}
	return words;
}
