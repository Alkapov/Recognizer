#pragma once
#include "Enums.h"
class Atom
{
public:
    char symbol = '0';
    TransliterationType type;
    Atom(char ch, TransliterationType type);
    Atom();
    ~Atom();
};              

