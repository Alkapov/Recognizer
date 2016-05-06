#pragma once
#include "TransliterationType.h"

class Atom
{
public:
    char symbol = '0';
    TransliterationType type;
    Atom(char ch, TransliterationType type);
    Atom();
    ~Atom();
};              

