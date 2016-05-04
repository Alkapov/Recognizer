#pragma once

#include "Atom.h"


                                       
using namespace std;

class TransliterationUnit
{
public:
    std::vector<Atom> Parse(string & input, SequenceStatus & status);
    TransliterationUnit();
    ~TransliterationUnit();
};

