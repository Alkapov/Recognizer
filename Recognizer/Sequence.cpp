#include "Sequence.h"



Sequence::Sequence(string source)
{
    this->Source = source;
}
SequenceStatus Sequence::getStatus()
{
    return this->Status;
}
void Sequence::setStatus(SequenceStatus status)
{
    this->Status = status;
}
string Sequence::getSource()
{
    return this->Source;
}
void Sequence::initTransliterationUnit(TransliterationUnit & unit)
{
    this->Atoms = unit.Parse(this->Source);
}



Sequence::~Sequence()
{
}
