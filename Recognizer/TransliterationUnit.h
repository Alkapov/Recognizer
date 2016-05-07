#pragma once

#include "Atom.h"
#include "stdafx.h"
#include "SequenceStatus.h"


class TransliterationUnit
{
public:
    static vector<Atom> Parse(string & input, SequenceStatus::SequenceStatus & status);
    TransliterationUnit();
    ~TransliterationUnit();
};

