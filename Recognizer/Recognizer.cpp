
#include "Recognizer.h"
#include "Sequence.h"

#include "Test.h"




Recognizer::Recognizer()
{

}

bool  Recognizer::Check(string input)
{
#if _DEBUG
    Test::pushMain(input);
#endif
    Sequence sequence(input);
    sequence.init(this->transliterationUnit, this->lexicalUnit, this->identificationUnit, this->syntaxUnit);
    return sequence.isAcceptable();
}

Recognizer::~Recognizer()
{
}
