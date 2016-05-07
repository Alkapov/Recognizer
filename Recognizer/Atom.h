#pragma once
#include "TransliterationType.h"

class Atom
{
public:
    char symbol = '0';
    TransliterationType::TransliterationType type;
    Atom(char ch, TransliterationType::TransliterationType type);
    Atom();
    ~Atom();
};              

