#pragma once

#include "stdafx.h"
#include "LexicalType.h"

class LexicalToken
{
public:
    string value = "";
    LexicalType type;
    LexicalToken();
    LexicalToken(char & value, LexicalType type);
    LexicalToken(string & value, LexicalType type);
    ~LexicalToken();
};
