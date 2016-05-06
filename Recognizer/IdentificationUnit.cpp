#include "IdentificationUnit.h"


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

LexicalType IdentificationUnit::Identificate(LexicalToken token)
{
    if (keywords.find(token.value) != keywords.end())
        return keywords[token.value];
    return LexicalType::NoKeyword;
}

void IdentificationUnit::Identification(vector<LexicalToken> & lexicalTokens, SequenceStatus & status)
{
#if _DEBUG
    printf("\nModule: IdentificationUnit.cpp\n");
    printf("   Input status: %s\n", status == SequenceStatus::Accepted ? "Accepted" : (status == SequenceStatus::Rejected ? "Rejected" : "Unidentified"));
#endif
    for (vector<LexicalToken>::iterator i = lexicalTokens.begin(); i != lexicalTokens.end() && status != Rejected; ++i)
        if (i->type == LexicalType::Keyword)
            i->type = Identificate(*i);
        else if (i->type == LexicalType::Identifier)
            if (Identificate(*i) != LexicalType::NoKeyword)
                status = Rejected;
#if _DEBUG

#define stringify( name ) # name
    const char * names[]
    {
        stringify(Keyword),
        stringify(Identifier),
        stringify(Equal),
        stringify(ValueDecimalNumber),
        stringify(ValueHexNumber),
        stringify(ValueExponentNumber),
        stringify(Semicolon),
        stringify(ValueString),
        stringify(ValueFloatNumber),
        stringify(KeywordAnd),
        stringify(KeywordEnd),
        stringify(KeywordNil),
        stringify(KeywordSet),
        stringify(KeywordArray),
        stringify(KeywordFile),
        stringify(KeywordNot),
        stringify(KeywordThen),
        stringify(KeywordBegin),
        stringify(KeywordFor),
        stringify(KeywordOf),
        stringify(KeywordTo),
        stringify(KeywordCase),
        stringify(KeywordFunction),
        stringify(KeywordOr),
        stringify(KeywordType),
        stringify(KeywordConst),
        stringify(KeywordGoto),
        stringify(KeywordPacked),
        stringify(KeywordUntil),
        stringify(KeywordDiv),
        stringify(KeywordIf),
        stringify(KeywordProcedure),
        stringify(KeywordVar),
        stringify(KeywordDo),
        stringify(KeywordIn),
        stringify(KeywordProgram),
        stringify(KeywordWhile),
        stringify(KeywordDownto),
        stringify(KeywordLabel),
        stringify(KeywordRecord),
        stringify(KeywordWith),
        stringify(KeywordElse),
        stringify(KeywordMod),
        stringify(KeywordRepeat),
        stringify(NoKeyword)
    };
    if (lexicalTokens.size()> 1)
        for (int i = 0; i < lexicalTokens.size(); ++i)
            cout << "      Token " << i + 1 << " = (" << lexicalTokens[i].value << ", " << names[lexicalTokens[i].type] << ")\n";
    cout << "   Output status: " << (status == SequenceStatus::Accepted ? "Accepted" : (status == SequenceStatus::Rejected ? "Rejected" : "Undenified")) << "\n";

#endif
}


IdentificationUnit::~IdentificationUnit()
{
}
