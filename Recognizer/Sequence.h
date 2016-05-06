#pragma once

#include "stdafx.h"
#include "LexicalToken.h"
#include "Recognizer.h"   
#include "SequenceStatus.h"

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
    string getSource() const;
    SequenceStatus getStatus() const;
    bool isAcceptable() const;
    void init(TransliterationUnit & TUnit, LexicalUnit & LUnit, IdentificationUnit & IUnit, SyntaxUnit & SUnit);

    ~Sequence();
};

