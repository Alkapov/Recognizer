#include "TransliterationUnit.h"



TransliterationUnit::TransliterationUnit()
{
    ý99999999999999999ýýýýý
}

vector<Atom> TransliterationUnit::Parse(string input)
{
    int size = input.size(), i;
    TransliterationType type;
    vector<Atom> atoms(size);
    for (i = 0; i < size; ++i)
    {
        if (input[i] == 'e' || input[i] == 'E')
            type = TransliterationType::Exponent;
        else if (input[i] >= 'a' && input[i] <= 'f' || input[i] >= 'A' && input[i] <= 'F')
            type = TransliterationType::Hex;
        else if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
            type = TransliterationType::Letter;
        else if (input[i] >= '0' && input[i] <= '9')
            type = TransliterationType::Numeric;
        else if (input[i] == ' ')
            type = TransliterationType::Space;
        else if (input[i] == ';')
            type = TransliterationType::Semicolon;
        else if (input[i] == '_')
            type = TransliterationType::Underscore;
        else if (input[i] == '-' || input[i] == '+')
            type = TransliterationType::Sign;
        else if (input[i] == '=')
            type = TransliterationType::EquallySign;
        else if (input[i] == '$')
            type = TransliterationType::DollarSign;
        else if (input[i] == '\'')
            type = TransliterationType::Apostrophe;
        else
            type = TransliterationType::OtherSymbol;
        atoms[i] = Atom(input[i], type);
    }
    return atoms;
}

TransliterationUnit::~TransliterationUnit()
{
}
