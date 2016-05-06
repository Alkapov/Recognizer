#pragma once



#include "LexicalToken.h"
#include "Atom.h"
#include "SequenceStatus.h"

using namespace std;
 

class LexicalUnit
{
public:
    vector<LexicalToken> Analize(vector<Atom> & sequence, SequenceStatus & status);
    LexicalUnit();
    ~LexicalUnit();
};

