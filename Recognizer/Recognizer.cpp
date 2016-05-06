
#include "Recognizer.h"
#include "Sequence.h"



Recognizer::Recognizer()
{

}

bool  Recognizer::Check(string input)
{
    Sequence sequence(input);
    sequence.init(this->transliterationUnit, this->lexicalUnit, this->identificationUnit, this->syntaxUnit);
    return sequence.isAcceptable();
}

Recognizer::~Recognizer()
{
}
