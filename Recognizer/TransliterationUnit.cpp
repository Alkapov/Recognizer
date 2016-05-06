#include "TransliterationUnit.h"


TransliterationUnit::TransliterationUnit()
{
                                  
}


std::vector<Atom> TransliterationUnit::Parse(string & input, SequenceStatus & status)
{
#if _DEBUG
    printf("\nModule: TransliterationUnit.cpp\n");
    printf("   Input status: %s\n", status == SequenceStatus::Accepted ? "Accepted" : (status == SequenceStatus::Rejected ? "Rejected" : "Unidentified"));
#endif

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
#if _DEBUG
    #define stringify( name ) # name
    const char * names[]
    {
        stringify(SignExponent),
        stringify(SignHexLetter),
        stringify(SignLetter),
        stringify(SignNumeric),
        stringify(SignDollar),
        stringify(SignApostrophe),
        stringify(SignSemicolon),
        stringify(SignUnderscope),
        stringify(SignPM),
        stringify(SignWhiteSpace),
        stringify(SignEqual),
        stringify(SignPoint),
        stringify(SignError)
    };
    
    for (int i = 0; i < sequence.size(); ++i)
        printf("      Atom %d = (%c, %s)\n", i + 1, sequence[i].symbol, names[sequence[i].type]);
    printf("   Output status: %s\n", status == SequenceStatus::Accepted ? "Accepted" : (status == SequenceStatus::Rejected ? "Rejected" : "Undenified"));

#endif
    return sequence;
}



TransliterationUnit::~TransliterationUnit()
{
}
