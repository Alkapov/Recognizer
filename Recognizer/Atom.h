#pragma once
#include "Enums.h"
class Atom
{
public:
    char symbol = '0';
    TransliterationType type = Letter;
    Atom(char ch, TransliterationType type);
    Atom();
    ~Atom();
};

