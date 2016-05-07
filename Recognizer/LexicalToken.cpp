#include "LexicalToken.h"


LexicalToken::LexicalToken(): type() {

}

LexicalToken::~LexicalToken()
{

}

LexicalToken::LexicalToken(char & value, LexicalType::LexicalType type)
{
    this->value.push_back(value);
    this->type = type;
}
LexicalToken::LexicalToken(std::string & value, LexicalType::LexicalType type)
{
    this->value = value;
    this->type = type;
}
