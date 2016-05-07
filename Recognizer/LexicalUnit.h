#pragma once


#include "stdafx.h"
#include "LexicalToken.h"
#include "Atom.h"
#include "SequenceStatus.h"

using namespace std;
 

class LexicalUnit
{
public:
    static vector<LexicalToken> Analize(vector<Atom> & sequence, SequenceStatus::SequenceStatus & status);
    LexicalUnit();
    ~LexicalUnit();
};

