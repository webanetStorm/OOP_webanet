#include "Cargo.h"

Cargo::Cargo( Base* parent, string name, int l, int w, int h ) : Base( parent, name )
{
	this->l = l;
	this->w = w;
	this->h = h;
}
