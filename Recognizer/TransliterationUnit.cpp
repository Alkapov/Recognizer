#include "TransliterationUnit.h"
#include "stdafx.h"
#include "Enums.h"
#include "Models.h"

TransliterationUnit::TransliterationUnit()
{
                                  
}

std::vector<Atom> TransliterationUnit::Parse(string & input, SequenceStatus & status)
{
    vector<Atom> sequence;
    if (status != SequenceStatus::Rejected)
        for (int i = 0; i < input.size() && status != SequenceStatus::Rejected; ++i)
            if (input[i] == 'e' || input[i] == 'E')
                sequence.push_back(Atom(input[i], TransliterationType::SignExponent));
            else  if ((input[i] >= 'a' &&  input[i] <= 'f') || (input[i] >= 'A' &&  input[i] <= 'F'))
                sequence.push_back(Atom(input[i], TransliterationType::SignHexLetter));
            else  if ((input[i] >= 'g' &&  input[i] <= 'z') || (input[i] >= 'G' &&  input[i] <= 'Z'))
                sequence.push_back(Atom(input[i], TransliterationType::SignHexLetter));
            else  if (input[i] >= '0' &&  input[i] <= '9')
                sequence.push_back(Atom(input[i], TransliterationType::SignNumeric));
            else  if (input[i] == '$')
                sequence.push_back(Atom(input[i], TransliterationType::SignDollar));
            else  if (input[i] == '\'')
                sequence.push_back(Atom(input[i], TransliterationType::SignApostrophe));
            else  if (input[i] == ';')
                sequence.push_back(Atom(input[i], TransliterationType::SignSemicolon));
            else  if (input[i] == '_')
                sequence.push_back(Atom(input[i], TransliterationType::SignUnderscope));
            else  if (input[i] == '+' || input[i] == '-')
                sequence.push_back(Atom(input[i], TransliterationType::SignPM));
            else  if (input[i] == ' ')
                sequence.push_back(Atom(input[i], TransliterationType::SignWhiteSpace));
            else  if (input[i] == '=')
                sequence.push_back(Atom(input[i], TransliterationType::SignEqual));
            else  if (input[i] == '.')
                sequence.push_back(Atom(input[i], TransliterationType::SignPoint));
            else
                status = SequenceStatus::Rejected;
    return sequence;
}



TransliterationUnit::~TransliterationUnit()
{
}
