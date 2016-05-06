#include "LexicalToken.h"


LexicalToken::LexicalToken(): type() {

}

LexicalToken::~LexicalToken()
{

}

LexicalToken::LexicalToken(char & value, LexicalType type)
{
    this->value.push_back(value);
    this->type = type;
}
LexicalToken::LexicalToken(string & value, LexicalType type)
{
    this->value = value;
    this->type = type;
}
