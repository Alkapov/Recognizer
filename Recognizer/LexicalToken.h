#pragma once

struct LexicalToken
{
    string value = "";
    LexicalType type;
    LexicalToken()
    {

    }                                   
    LexicalToken(char & value, LexicalType type)
    {
        this->value.push_back(value);
        this->type = type;
    }
    LexicalToken(string & value, LexicalType type)
    {
        this->value = value;
        this->type = type;
    }
};