#pragma once
#include "stdafx.h"


#include "LexicalToken.h"
#include "SequenceStatus.h"

class IdentificationUnit
{
    unordered_map<string, LexicalType> keywords;
public:   
    void Identification(vector<LexicalToken> & lexicalTokens, SequenceStatus & status);
    LexicalType Identificate(LexicalToken token);
    IdentificationUnit();
    ~IdentificationUnit();
};                         

