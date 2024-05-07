#include "Base.h"

Base::Base( Base* pParent, string _name )
{
	this->_name = _name;
	this->pParent = pParent;
	if ( pParent != nullptr )
	{
		pParent->pChilds.push_back( this );
	}
}

Base::~Base()
{
	get_root()->delete_links( this );
	for ( int i = 0; i < pChilds.size(); i++ )
	{
		delete pChilds[i];
	}
}

bool Base::set_name( string s_new_name )
{
	if ( get_head() != nullptr )
	{
		for ( int i = 0; i < get_head()->pChilds.size(); i++ )
		{
			if ( get_head()->pChilds[i]->get_name() == s_new_name )
			{
				return false;
			}
		}
	}
	_name = s_new_name;
	return true;
}

void Base::print_tree( string delay )
{
	cout << endl << delay << get_name();
	for ( auto p_sub : pChilds )
	{
		p_sub->print_tree( delay + "    " );
	}
}

void Base::print_ready( string delay )
{
	cout << endl << delay;
	get_ready( get_name() );
	for ( auto p_sub : pChilds )
	{
		p_sub->print_ready( delay + "    " );
	}
}

string Base::get_name()
{
	return _name;
}

Base* Base::get_head()
{
	return pParent;
}

Base* Base::get_sub_obj( string _name )
{
	for ( int i = 0; i < pChilds.size(); i++ )
	{
		if ( pChilds[i]->_name == _name )
		{
			return pChilds[i];
		}
	}
	return nullptr;
}

int Base::count( string name )
{
	int count = 0;
	if ( get_name() == name )
	{
		count++;
	}
	for ( int i = 0; i < pChilds.size(); i++ )
	{
		count += pChilds[i]->count( name );
	}
	return count;
}

Base* Base::search_by_name( string name )
{
	if ( _name == name )
	{
		return this;
	}
	Base* p_result = nullptr;
	for ( int i = 0; i < pChilds.size(); i++ )
	{
		p_result = pChilds[i]->search_by_name( name );
		if ( p_result != nullptr )
		{
			return p_result;
		}
	}
	return nullptr;
}

Base* Base::search_cur( string name )
{
	if ( count( name ) != 1 )
	{
		return nullptr;
	}
	return search_by_name( name );
}

Base* Base::search_from_root( string name )
{
	if ( pParent != nullptr )
	{
		return pParent->search_from_root( name );
	}
	else
	{
		return search_cur( name );
	}
}

void Base::set_ready( int s_new_ready )
{
	if ( s_new_ready != 0 )
	{
		if ( pParent == nullptr || pParent != nullptr && pParent->_readiness != 0 )
		{
			_readiness = s_new_ready;
		}
	}
	else
	{
		_readiness = s_new_ready;
		for ( int i = 0; i < pChilds.size(); i++ )
		{
			pChilds[i]->set_ready( s_new_ready );
		}
	}
}

void Base::get_ready( string name )
{
	if ( get_name() == name )
	{
		if ( _readiness != 0 )
		{
			cout << get_name() << " is ready";
		}
		else
		{
			cout << get_name() << " is not ready";
		}
	}
	else
	{
		for ( int i = 0; i < pChilds.size(); i++ )
		{
			return pChilds[i]->get_ready( name );
		}
	}
}

bool Base::change_head_obj( Base* new_head_obj )
{
	if ( new_head_obj != nullptr )
	{
		Base* temp = new_head_obj;
		while ( temp != nullptr )
		{
			temp = temp->pParent;
			if ( temp == this )
			{
				return false;
			}
		}
		if ( new_head_obj->get_sub_obj( get_name() ) == nullptr && pParent != nullptr )
		{
			pParent->pChilds.erase( find( pParent->pChilds.begin(), pParent->pChilds.end(), this ) );
			new_head_obj->pChilds.push_back( this );
			pParent = new_head_obj;
			return true;
		}
	}
	return false;
}

void Base::delete_subordinate_obj( string name )
{
	Base* subordinate_obj = get_sub_obj( name );
	if ( subordinate_obj != nullptr )
	{
		pChilds.erase( find( pChilds.begin(), pChilds.end(), subordinate_obj ) );
		delete subordinate_obj;
	}
}

Base* Base::find_obj_by_coord( string s_object_path )
{
	if ( s_object_path == "" )
	{
		return nullptr;
	}
	Base* head_obj = this;
	string s_path_item;
	if ( s_object_path == "." || s_object_path == "/" )
	{
		return head_obj;
	}
	if ( s_object_path[0] == '.' )
	{
		s_object_path.erase( s_object_path.begin() );
		return search_by_name( s_object_path );
	}
	if ( s_object_path[1] == '/' && s_object_path[0] == '/' )
	{
		s_object_path.erase( s_object_path.begin() );
		s_object_path.erase( s_object_path.begin() );
		return this->search_from_root( s_object_path );
	}
	if ( s_object_path[0] == '/' )
	{
		s_object_path.erase( s_object_path.begin() );
		while ( head_obj->pParent != nullptr )
		{
			head_obj = head_obj->pParent;
		}
	}
	stringstream ss_path( s_object_path );
	while ( getline( ss_path, s_path_item, '/' ) )
	{
		head_obj = head_obj->get_sub_obj( s_path_item );
		if ( head_obj == nullptr )
		{
			return nullptr;
		}
	}
	return head_obj;
}

void Base::print_from_current( int n )
{
	cout << endl;
	for ( int i = 0; i < n; i++ )
	{
		cout << "    ";
	}
	cout << _name;
	for ( auto p_subordinate_object : pChilds )
	{
		p_subordinate_object->print_from_current( n + 1 );
	}
}

void Base::set_connection( TYPE_SIGNAL pSignal, Base* p_target, TYPE_HANDLER p_handler )
{
	Connection* p_value;
	for ( int i = 0; i < _connections.size(); i++ )
	{
		if ( _connections[i]->pSignal == pSignal &&
			_connections[i]->p_handler == p_handler &&
			_connections[i]->p_target == p_target )
		{
			return;
		}
	}
	p_value = new Connection();
	p_value->pSignal = pSignal;
	p_value->p_handler = p_handler;
	p_value->p_target = p_target;

	_connections.push_back( p_value );
}

void Base::delete_connection( TYPE_SIGNAL pSignal, Base* p_target, TYPE_HANDLER p_handler )
{
	for ( auto p_it = _connections.begin(); p_it != _connections.end(); p_it++ )
	{
		if ( ( *p_it )->pSignal == pSignal &&
			( *p_it )->p_target == p_target &&
			( *p_it )->p_handler == p_handler )
		{
			delete* p_it;
			p_it = _connections.erase( p_it );
			p_it--;
		}
	}
}

void Base::emit_signal( TYPE_SIGNAL pSignal, string s_massege )
{
	if ( _readiness != 0 )
	{
		TYPE_HANDLER pHandler;
		Base* pObject;
		( this->*pSignal )( s_massege );
		for ( int i = 0; i < _connections.size(); i++ )
		{
			if ( _connections[i]->pSignal == pSignal )
			{
				pHandler = _connections[i]->p_handler;
				pObject = _connections[i]->p_target;
				if ( pObject->_readiness != 0 )
				{
					( pObject->*pHandler )( s_massege );
				}
			}
		}
	}
}
string Base::get_path()
{
	Base* pParent = this->get_head();
	if ( pParent != nullptr )
	{
		if ( pParent->get_head() == nullptr )
		{
			return pParent->get_path() + _name;
		}
		else
		{
			return pParent->get_path() + "/" + _name;
		}
	}
	return "/";
}

void Base::setState( int state )
{
	if ( state == 0 )
	{
		this->_readiness = 0;
		for ( int i = 0; i < pChilds.size(); i++ )
		{
			pChilds[i]->setState( 0 );
		}
		return;
	}
	if ( this->pParent == nullptr || this->pParent->_readiness != 0 )
	{
		this->_readiness = state;
	}
}



void Base::delete_links( Base* targ )
{
	for ( auto p_it = _connections.begin(); p_it != _connections.end(); p_it++ )
	{
		if ( ( *p_it )->p_target == targ )
		{
			delete ( *p_it );
			_connections.erase( p_it );
			p_it--;
		}
	}

	for ( auto p_sub : pChilds )
	{
		p_sub->delete_links( targ );
	}
}

Base* Base::get_root()
{
	if ( pParent != nullptr )
	{
		pParent->get_root();
	}
	return this;
}