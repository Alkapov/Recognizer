#define _CRT_SECURE_NO_WARNINGS

#include "Recognizer.h"

#include "Enums.h"
#include "Units.h"
#include "Models.h"

using namespace std;

Recognizer::Recognizer()
{
    transliterationUnit = TransliterationUnit();
    lexicalUnit = LexicalUnit();
    identificationUnit = IdentificationUnit();
    syntaxUnit = SyntaxUnit();
}

string Read(string fileName)
{
    freopen(fileName.c_str(), "r", stdin);
    string buff;
    getline(cin, buff);
    fclose(stdin);
    return buff;
}

bool Recognizer::Check(string input)
{
    Sequence sequence(input);
    return sequence.isAcceptable();
}

Recognizer::~Recognizer()
{
}
