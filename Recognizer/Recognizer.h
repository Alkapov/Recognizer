#pragma once 

#include "stdafx.h"
#include "TransliterationUnit.h"
#include "LexicalUnit.h"
#include "IdentificationUnit.h"
#include "SyntaxUnit.h"


class Recognizer
{

public:

    TransliterationUnit transliterationUnit = TransliterationUnit();
    LexicalUnit lexicalUnit = LexicalUnit();
    IdentificationUnit identificationUnit = IdentificationUnit();
    SyntaxUnit syntaxUnit = SyntaxUnit();

    Recognizer();
    bool Check(string input);
    ~Recognizer();
};

