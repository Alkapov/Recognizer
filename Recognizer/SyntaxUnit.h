#pragma once

#include "stdafx.h"
#include "Enums.h"
#include "Models.h"

class SyntaxUnit
{
public:
    void Verificate(vector<LexicalToken> & lexicalTokens, SequenceStatus & status);
    SyntaxUnit();                    
    ~SyntaxUnit();
};

