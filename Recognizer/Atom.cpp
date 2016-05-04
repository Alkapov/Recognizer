#include "Atom.h"



Atom::Atom(char ch, TransliterationType type)
{
    this->symbol = ch;
    this->type = type;
}

Atom::Atom()
{
}

Atom::~Atom()
{
}
