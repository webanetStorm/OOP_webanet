#include "Controller.h" 
#include "Area.h" 
#include "Output.h" 
#include "Cargo.h" 	 	 

#include <cmath> 

Controller::Controller( Base* parent, string name ) : Base( parent, name )
{
}
void Controller::handler_f( string command )
{
    vector<string> words = get_words( command );

    if ( command.find( "Submit the cargo" ) != string::npos )
    {
        floor_sqr_num = stoi( words[4] );   
        find_cargo( words[3] );
    }
    else if ( command == "Condition of the tower crane" )
    {
        crane_info();
    }
    else if ( command == "" )
    {
        if ( get_state() != 1 )
            work( carg_id );
    }
    else
    {
        n = stoi( words[0] );   
        m = stoi( words[1] );   
        E = stoi( words[2] );
    }
}  

void Controller::find_cargo( string id )
{
    Base* root = get_parent();  
    string text = "";
    auto cargo = root->find_in_tree( id );

    if ( !cargo )
    {
        text = "Cargo " + id + " not found";
    }
    else
    {
        auto par_obj = cargo->get_parent();

        if ( par_obj == this )
        {
            text = "The cargo " + id + " is located on the hook of the tower crane";
        }
        else if ( par_obj->get_name() == "Floor area" )
        {
            text = "The cargo " + id + " is located on the floor";
        }
        else
        {
            Area* area1 = (Area*)root->get_child( "Cargo area 1" );
            Area* area2 = (Area*)root->get_child( "Cargo area 2" );    
            Area* area3 = (Area*)root->get_child( "Cargo area 3" );

            bool is_in_end = false;

            for ( int i = 0; i < 9; i++ )
            {
                bool cond1 = ( area1->squares[i].size() != 0 ) && ( area1 -> squares[i].back()->get_name() == id );
                bool cond2 = ( area2->squares[i].size() != 0 ) && ( area2 -> squares[i].back()->get_name() == id );
                bool cond3 = ( area3->squares[i].size() != 0 ) && ( area3 -> squares[i].back()->get_name() == id );     
                
                if ( cond1 || cond2 || cond3 )
                {
                    is_in_end = true;
                    break;
                }
            }

            if ( !is_in_end )     
                text = "The cargo " + id + " is not available";
        }
    }
    if ( text != "" )
    {
        auto output = root->get_child( "Output object" );   
        emit_signal( SIGNAL_D( Base::signal_f ), output, text );
    }
    else work( id );
}
void Controller::work( string id )
{
    Cargo* cargo = (Cargo*)get_parent()->find_in_tree( id );  Area* area = (Area*)( cargo->get_parent() );

    switch ( get_state() )
    {
        case 1:
        {
            carg_id = id;

            int sqr_num = area->get_num( cargo );

            int area_num = area->get_name().back() - '0';

            int x, y;    
            switch ( area_num )
            {
                case 1:
                    x = 16 - ( sqr_num - 1 ) % 3 * 4;      
                    y = 2 + ( sqr_num - 1 ) / 3 * 4;      
                    angle = 180 + atan2( y, x ) * 180 / M_PI;
                break;     
                case 2:
                    x = -4 + ( sqr_num - 1 ) % 3 * 4;     
                    y = 14 + ( sqr_num - 1 ) / 3 * 4;
                    angle = 180 + atan2( y, x ) * 180 / M_PI + ( 90 - atan2( y, x ) * 180 / M_PI ) * ( ( sqr_num - 1 ) % 3 );
                break;     
                case 3:
                    x = 8 + ( sqr_num - 1 ) % 3 * 4;     
                    y = 2 + ( sqr_num - 1 ) / 3 * 4;
                    angle = 360 - atan2( y, x ) * 180 / M_PI;
                    break;
            }
            d = sqrt( x * x + y * y );

            break;
        }
        case 2:
        {
            int sqr_num = area->get_num( cargo );

            cargo->set_parent( this );    
            area->del_from_square( sqr_num, cargo );

            break;
        }
        case 3:    
            break;
        case 4:
        {

            int x, y;
            x = 2 - m / 2 + ( floor_sqr_num - 1 ) % ( m / 4 ) * 4;   
            y = 2 + n - ( floor_sqr_num - 1 ) / ( m / 4 ) * 4;

            if ( x == 0 )     
                angle = 90;
            else
                angle = atan2( y, x ) * 180 / M_PI;

            if ( angle == 155 )
                angle++;

            d = sqrt( x * x + y * y );
            break;
        }
        case 5:
        {
            Area* area_floor = (Area*)( get_parent()->get_child( "Floor area" ) );    
            cargo->set_parent( area_floor );
            area_floor->squares[floor_sqr_num - 1].push_back( cargo );

            angle = 0;
            break;
        }
        case 6:    
            break;
    }

    set_state( get_state() + 1 );
    if ( get_state() > 6 )
        set_state( 1 );
}
void Controller::crane_info()
{
    auto output = get_parent()->get_child( "Output object" );
    string text = "Tower crane " + to_string( angle ) + "  " + to_string( d );  
    emit_signal( SIGNAL_D( Base::signal_f ), output, text );
}
