#pragma once
#include "stdafx.h"
#include "Units.h"

class Recognizer
{
    TransliterationUnit transliterationUnit;
    LexicalUnit lexicalUnit;
    IdentificationUnit identificationUnit;
    SyntaxUnit syntaxUnit;

public:
    Recognizer();                     
    bool Check(string input);
    ~Recognizer();
};

