#include "App.h"

#include <iostream>
using namespace std;

App::App( Base* parent, string name ) : Base( nullptr, name )
{
}

void App::signal_f( string& command )
{
	Base::signal_f( command );
}

void App::handler_f( string command )
{
	data = command;
	Base::handler_f( command );
}

void App::build_tree()
{
	Base* input = new Input( this );

	auto controller = new Controller( this );

	auto area1 = new Area( this, "Cargo area 1" );
	area1->set_count_sqr( 9 );
	auto area2 = new Area( this, "Cargo area 2" );
	area2->set_count_sqr( 9 );
	auto area3 = new Area( this, "Cargo area 3" );
	area3->set_count_sqr( 9 );

	auto area_floor = new AreaFloor( this, "Floor area" );

	auto output = new Output( this );

	this->set_state( 1 );
	input->set_state( 1 );
	controller->set_state( 1 );
	area1->set_state( 1 );
	area2->set_state( 1 );
	area3->set_state( 1 );
	area_floor->set_state( 1 );
	output->set_state( 1 );

	set_connect( SIGNAL_D( Base::signal_f ), input, HANDLER_D( Base::handler_f ) );
	set_connect( SIGNAL_D( Base::signal_f ), controller, HANDLER_D( Base::handler_f ) );
	set_connect( SIGNAL_D( Base::signal_f ), area1, HANDLER_D( Base::handler_f ) );
	set_connect( SIGNAL_D( Base::signal_f ), area2, HANDLER_D( Base::handler_f ) );
	set_connect( SIGNAL_D( Base::signal_f ), area3, HANDLER_D( Base::handler_f ) );
	set_connect( SIGNAL_D( Base::signal_f ), area_floor, HANDLER_D( Base::handler_f ) );
	set_connect( SIGNAL_D( Base::signal_f ), output, HANDLER_D( Base::handler_f ) );

	controller->set_connect( SIGNAL_D( Base::signal_f ), output, HANDLER_D( Base::handler_f ) );

	area1->set_connect( SIGNAL_D( Base::signal_f ), output, HANDLER_D( Base::handler_f ) );
	area2->set_connect( SIGNAL_D( Base::signal_f ), output, HANDLER_D( Base::handler_f ) );
	area3->set_connect( SIGNAL_D( Base::signal_f ), output, HANDLER_D( Base::handler_f ) );
	area_floor->set_connect( SIGNAL_D( Base::signal_f ), output, HANDLER_D( Base::handler_f ) );

	input->set_connect( SIGNAL_D( Base::signal_f ), this, HANDLER_D( Base::handler_f ) );


	int n, m, E;
	int area_num, sqr_num;
	string id;
	float l, w, h;
	vector<string> words;
	bool is_first = true;

	while ( true )
	{
		emit_signal( SIGNAL_D( Base::signal_f ), input, data );

		if ( data == "End of cargos" )
			break;

		if ( is_first )
		{
			emit_signal( SIGNAL_D( Base::signal_f ), controller, data );
			emit_signal( SIGNAL_D( Base::signal_f ), area_floor, data );

			is_first = false;
		}
		else
		{
			words = get_words( data );

			area_num = stoi( words[0] );
			sqr_num = stoi( words[1] );
			id = words[2];
			l = stof( words[3] );
			w = stof( words[4] );
			h = stof( words[5] );

			Area* area = nullptr;
			switch ( area_num )
			{
				case 1:
					area = (Area*)area1;
					break;
				case 2:
					area = (Area*)area2;
					break;
				case 3:
					area = (Area*)area3;
					break;
			}

			auto cargo = new Cargo( area, id, l, w, h );
			cargo->set_state( 1 );
			area->squares[sqr_num - 1].push_back( cargo );
		}
	}
}


int App::exec_app()
{
	Input* input = (Input*)( get_child( "Input object" ) );
	Controller* controller = (Controller*)( get_child( "Controller object" ) );
	Area* area1 = (Area*)( get_child( "Cargo area 1" ) );
	Area* area2 = (Area*)( get_child( "Cargo area 2" ) );
	Area* area3 = (Area*)( get_child( "Cargo area 3" ) );
	AreaFloor* area_floor = (AreaFloor*)( get_child( "Floor area" ) );
	Output* output = (Output*)( get_child( "Output object" ) );

	data = "Ready to work";
	emit_signal( SIGNAL_D( Base::signal_f ), output, data );

	while ( true )
	{
		emit_signal( SIGNAL_D( Base::signal_f ), input, data );

		if ( data == "Turn off the system" )
		{
			emit_signal( SIGNAL_D( Base::signal_f ), output, data );
			break;
		}


		if ( data == "SHOWTREE" )
		{
			SHOWTREE();
		}
		else if ( data.find( "Submit the cargo" ) != string::npos )
		{
			emit_signal( SIGNAL_D( Base::signal_f ), controller, data );
			continue;
		}
		else if ( data.find( "Condition of the cargo area" ) != string::npos )
		{
			if ( data.find( "1" ) != string::npos )
				emit_signal( SIGNAL_D( Base::signal_f ), area1, data );
			else if ( data.find( "2" ) != string::npos )
				emit_signal( SIGNAL_D( Base::signal_f ), area2, data );
			else if ( data.find( "3" ) != string::npos )
				emit_signal( SIGNAL_D( Base::signal_f ), area3, data );
		}
		else if ( data.find( "Cargo condition" ) != string::npos )
		{
			vector<string> words = get_words( data );
			string cargo_id = words[2];

			if ( area1->find_in_tree( cargo_id ) )
				emit_signal( SIGNAL_D( Base::signal_f ), area1, data );
			else if ( area2->find_in_tree( cargo_id ) )
				emit_signal( SIGNAL_D( Base::signal_f ), area2, data );
			else if ( area3->find_in_tree( cargo_id ) )
				emit_signal( SIGNAL_D( Base::signal_f ), area3, data );
			else if ( area_floor->find_in_tree( cargo_id ) )
				emit_signal( SIGNAL_D( Base::signal_f ), area_floor, data );
			else if ( controller->find_in_tree( cargo_id ) )
			{
				data += ": in hook";
				emit_signal( SIGNAL_D( Base::signal_f ), output, data );
			}
			else
			{
				data = "Cargo " + cargo_id + " not found";
				emit_signal( SIGNAL_D( Base::signal_f ), output, data );
			}
		}
		else if ( data.find( "Condition of the tower crane" ) != string::npos )
		{
			emit_signal( SIGNAL_D( Base::signal_f ), controller, data );
		}
		else if ( data.find( "Floor condition" ) != string::npos )
		{
			emit_signal( SIGNAL_D( Base::signal_f ), area_floor, data );
		}
		else
		{
		}

		data = "";
		emit_signal( SIGNAL_D( Base::signal_f ), controller, data );
	}

	return 0;
}

void App::SHOWTREE()
{
	cout << endl << "Object tree";
	print_tree_states();
}
