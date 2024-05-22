#include "Cargo.h"


Cargo::Cargo( Base* parent, string name, int l, int w, int h ) : Base( parent, name )
{
	this->Length = l;
	this->Width = w;
	this->Height = h;
}
