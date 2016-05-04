#pragma once
#include <string>
#include <vector>
#include "Enums.h"
#include "Models.h"
#include "Units.h"
using namespace std;

class Sequence
{
    string Source;
    SequenceStatus Status = SequenceStatus::Unidentified;
    vector<Atom> Atoms;
    vector<LexicalToken> LexicalTokens;

public:
    Sequence(string source);
    string getSource();
    SequenceStatus getStatus();
    void setStatus(SequenceStatus status);
    void initTransliterationUnit(TransliterationUnit & unit);
    void initLexicalUnit(LexicalUnit & unit);
    void initIdentificationUnit(IdentificationUnit & unit);
    void initSyntaxUnit(SyntaxUnit & unit);
    ~Sequence();
};

