#include "Cargo.h"


Cargo::Cargo( Base* parent, string name, int length, int width, int height ) : Base( parent, name )
{
	this->_length = length;
	this->_width = width;
	this->_height = height;
}
