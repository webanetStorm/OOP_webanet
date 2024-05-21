#include "Cargo.h"


Cargo::Cargo( Base* pParent, string name, int length, int width, int height ) : Base( pParent, name )
{
	this->Length = length;
	this->Width = width;
	this->Height = height;
}
