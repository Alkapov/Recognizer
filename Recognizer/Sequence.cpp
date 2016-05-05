#include "Sequence.h"


void Sequence::init(TransliterationUnit & TUnit, LexicalUnit & LUnit, IdentificationUnit & IUnit, SyntaxUnit & SUnit)
{
    this->initTransliterationUnit(TUnit);
    this->initLexicalUnit(LUnit);
    this->initIdentificationUnit(IUnit);
    this->initSyntaxUnit(SUnit);
}
Sequence::Sequence(string source)
{
    this->Source = source;
}
SequenceStatus Sequence::getStatus()
{
    return this->Status;
}
bool Sequence::isAcceptable()
{
    return this->Status == SequenceStatus::Accepted;
}
string Sequence::getSource()
{
    return this->Source;
}
void Sequence::initTransliterationUnit(TransliterationUnit & unit)
{
    this->Atoms = unit.Parse(this->Source, this->Status);
}
void Sequence::initLexicalUnit(LexicalUnit & unit)
{
    this->LexicalTokens = unit.Analize(this->Atoms, this->Status);
}
void Sequence::initIdentificationUnit(IdentificationUnit & unit)
{
    unit.Identification(this->LexicalTokens, this->Status);
}
void Sequence::initSyntaxUnit(SyntaxUnit & unit)
{
    unit.Verificate(this->LexicalTokens, this->Status);
}

Sequence::~Sequence()
{
}
