#pragma once
#include "Atom.h"
#include <vector>
using namespace std;

class TransliterationUnit
{
public:
    std::vector<Atom> Parse(string input);
    TransliterationUnit();
    ~TransliterationUnit();
};

