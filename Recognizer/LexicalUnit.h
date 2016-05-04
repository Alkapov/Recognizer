#pragma once

#include "Enums.h"
#include "Models.h"
#include <vector>
#include <string>
using namespace std;


class LexicalUnit
{
public:
    vector<string> Analize(vector<Atom> sequence);
    LexicalUnit();
    ~LexicalUnit();
};

