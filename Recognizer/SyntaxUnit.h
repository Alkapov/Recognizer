#pragma once

#include "stdafx.h"
#include "LexicalToken.h"
#include "SequenceStatus.h"

class SyntaxUnit
{
public:
    void Verificate(vector<LexicalToken> & lexicalTokens, SequenceStatus & status);
    SyntaxUnit();                    
    ~SyntaxUnit();
};

