#include "IdentificationUnit.h"
#include "Test.h"


IdentificationUnit::IdentificationUnit()
{
    this->keywords.insert(make_pair("and", LexicalType::KeywordAnd));
    this->keywords.insert(make_pair("end", LexicalType::KeywordEnd));
    this->keywords.insert(make_pair("nil", LexicalType::KeywordNil));
    this->keywords.insert(make_pair("set", LexicalType::KeywordSet));
    this->keywords.insert(make_pair("array", LexicalType::KeywordArray));
    this->keywords.insert(make_pair("file", LexicalType::KeywordFile));
    this->keywords.insert(make_pair("not", LexicalType::KeywordNot));
    this->keywords.insert(make_pair("then", LexicalType::KeywordThen));
    this->keywords.insert(make_pair("begin", LexicalType::KeywordAnd));
    this->keywords.insert(make_pair("for", LexicalType::KeywordFor));
    this->keywords.insert(make_pair("of", LexicalType::KeywordOf));
    this->keywords.insert(make_pair("to", LexicalType::KeywordTo));
    this->keywords.insert(make_pair("case", LexicalType::KeywordCase));
    this->keywords.insert(make_pair("function", LexicalType::KeywordFunction));
    this->keywords.insert(make_pair("or", LexicalType::KeywordOr));
    this->keywords.insert(make_pair("type", LexicalType::KeywordType));
    this->keywords.insert(make_pair("const", LexicalType::KeywordConst));
    this->keywords.insert(make_pair("goto", LexicalType::KeywordGoto));
    this->keywords.insert(make_pair("packed", LexicalType::KeywordPacked));
    this->keywords.insert(make_pair("until", LexicalType::KeywordUntil));
    this->keywords.insert(make_pair("div", LexicalType::KeywordDiv));
    this->keywords.insert(make_pair("if", LexicalType::KeywordIf));
    this->keywords.insert(make_pair("procedure", LexicalType::KeywordProcedure));
    this->keywords.insert(make_pair("var", LexicalType::KeywordVar));
    this->keywords.insert(make_pair("do", LexicalType::KeywordDo));
    this->keywords.insert(make_pair("in", LexicalType::KeywordIn));
    this->keywords.insert(make_pair("program", LexicalType::KeywordProgram));
    this->keywords.insert(make_pair("while", LexicalType::KeywordWhile));
    this->keywords.insert(make_pair("downto", LexicalType::KeywordDownto));
    this->keywords.insert(make_pair("label", LexicalType::KeywordLabel));
    this->keywords.insert(make_pair("record", LexicalType::KeywordRecord));
    this->keywords.insert(make_pair("with", LexicalType::KeywordWith));
    this->keywords.insert(make_pair("else", LexicalType::KeywordElse));
    this->keywords.insert(make_pair("mod", LexicalType::KeywordMod));
    this->keywords.insert(make_pair("repeat", LexicalType::KeywordRepeat));
}

string IdentificationUnit::toLower(string input) const
{
    for (int i = 0; i < input.size(); ++i)
        input[i] = tolower(input[i]);
    return  input;
}

LexicalType::LexicalType IdentificationUnit::Identificate(LexicalToken token)
{
    if (keywords.find(toLower(token.value)) != keywords.end())
        return keywords[token.value];
    return LexicalType::NoKeyword;
}

void IdentificationUnit::Identification(vector<LexicalToken> & lexicalTokens, SequenceStatus::SequenceStatus & status)
{
#if _DEBUG
    Test::pushIn<IdentificationUnit>(status);
#endif
    for (vector<LexicalToken>::iterator i = lexicalTokens.begin(); i != lexicalTokens.end() && status != SequenceStatus::Rejected; ++i)
        if (i->type == LexicalType::Keyword)
            i->type = Identificate(*i);
        else if (i->type == LexicalType::Identifier)
            if (Identificate(*i) != LexicalType::NoKeyword)
                status = SequenceStatus::Rejected;
#if _DEBUG
    Test::pushOut(status, lexicalTokens);
#endif
}


IdentificationUnit::~IdentificationUnit()
{
}
