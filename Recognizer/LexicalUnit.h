#pragma once

#include "Enums.h"
#include "Models.h"

using namespace std;
 

class LexicalUnit
{
public:
    vector<LexicalToken> Analize(vector<Atom> & sequence, SequenceStatus & status);
    LexicalUnit();
    ~LexicalUnit();
};

