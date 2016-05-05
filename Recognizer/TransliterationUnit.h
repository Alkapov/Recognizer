#pragma once

#include "Atom.h"
#include "stdafx.h"

class TransliterationUnit
{
public:
    vector<Atom> Parse(string & input, SequenceStatus & status);
    TransliterationUnit();
    ~TransliterationUnit();
};

