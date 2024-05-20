#include "Cargo.h"


Cargo::Cargo( Base* pParent, string name, int l, int w, int h ) : Base( pParent, name )
{
	this->l = l;
	this->w = w;
	this->h = h;
}
