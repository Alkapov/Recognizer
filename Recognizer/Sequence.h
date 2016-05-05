#pragma once

#include "Enums.h"
#include "Models.h"
#include "Units.h"
#include "stdafx.h"
using namespace std;

class Sequence
{
    string Source = "";
    SequenceStatus Status = SequenceStatus::Unidentified;
    vector<Atom> Atoms;
    vector<LexicalToken> LexicalTokens;

    void initTransliterationUnit(TransliterationUnit & unit);
    void initLexicalUnit(LexicalUnit & unit);
    void initIdentificationUnit(IdentificationUnit & unit);
    void initSyntaxUnit(SyntaxUnit & unit);

public:


    Sequence(string source);
    string getSource();
    SequenceStatus getStatus();
    bool isAcceptable();

    void init(TransliterationUnit & TUnit, LexicalUnit & LUnit, IdentificationUnit & IUnit, SyntaxUnit & SUnit);

    ~Sequence();
};

