#include "Atom.h"



Atom::Atom(char ch, TransliterationType::TransliterationType type)
{
    this->symbol = ch;
    this->type = type;         
}

Atom::Atom(): type() {

}

Atom::~Atom()
{
}
