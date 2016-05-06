#include "LexicalUnit.h"
#include "LexicalStatus.h"
#include "LexicalType.h"

LexicalUnit::LexicalUnit()
{

}



vector<LexicalToken> LexicalUnit::Analize(vector<Atom> & sequence, SequenceStatus & status)
{
#if _DEBUG
    printf("\nModule: LexicalUnit.cpp\n");
    printf("   Input status: %s\n", status == SequenceStatus::Accepted ? "Accepted" : (status == SequenceStatus::Rejected ? "Rejected" : "Unidentified"));
#endif
    vector<LexicalToken> lexicalTokens(1);
    LexicalStatus condition = LexicalStatus::LexicalStart;
    for (vector<Atom>::iterator i = sequence.begin(); i != sequence.end() && status != SequenceStatus::Rejected; ++i)
        switch (condition)
        {
        case LexicalStatus::LexicalStart:
            if (i->type == TransliterationType::SignWhiteSpace)
                continue;
            else if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::SignHexLetter || i->type == TransliterationType::SignLetter)
                condition = LexicalStatus::LexicalKeyword, lexicalTokens.back().type = LexicalType::Keyword, lexicalTokens.back().value.push_back(i->symbol);
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::LexicalKeyword:
            if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::SignHexLetter || i->type == TransliterationType::SignLetter)
                lexicalTokens.back().type = LexicalType::Keyword, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignWhiteSpace)
                condition = LexicalStatus::LexicalWhiteSpace1, lexicalTokens.push_back(LexicalToken());
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::LexicalWhiteSpace1:
            if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::SignHexLetter || i->type == TransliterationType::SignLetter)
               condition = LexicalIdentifier, lexicalTokens.back().type = LexicalType::Identifier, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignWhiteSpace)
                continue;
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::LexicalIdentifier:
            if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::SignHexLetter || i->type == TransliterationType::SignLetter || i->type == TransliterationType::SignNumeric || i->type == TransliterationType::SignUnderscope)
                lexicalTokens.back().type = LexicalType::Identifier, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignWhiteSpace)
                condition = LexicalStatus::LexicalWhiteSpace2;
            else if (i->type == TransliterationType::SignEqual)
                condition = LexicalStatus::LexicalUndenifiedValue, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Equal)), lexicalTokens.push_back(LexicalToken());
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::LexicalWhiteSpace2:
            if (i->type == TransliterationType::SignWhiteSpace)
                continue;
            else if (i->type == TransliterationType::SignEqual)
                condition = LexicalStatus::LexicalUndenifiedValue, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Equal)), lexicalTokens.push_back(LexicalToken());
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::LexicalUndenifiedValue:
            if (i->type == TransliterationType::SignNumeric)
                condition = LexicalStatus::LexicalNumericValue1, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignDollar)
                condition = LexicalStatus::LexicalHexValue, lexicalTokens.back().type = LexicalType::ValueHexNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignApostrophe)
                condition = LexicalStatus::LexicalStringValue, lexicalTokens.back().type = LexicalType::ValueString, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignPM)
                condition = LexicalStatus::LexicalUndenifiedNumericValue, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignWhiteSpace)
                continue;
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::LexicalStringValue:
            if (i->type == TransliterationType::SignApostrophe)
                condition = LexicalStatus::LexicalSemicolon, lexicalTokens.back().value.push_back(i->symbol);
            else
                lexicalTokens.back().type = LexicalType::ValueString, lexicalTokens.back().value.push_back(i->symbol);
            break;
        case LexicalStatus::LexicalUndenifiedNumericValue:
            if (i->type == TransliterationType::SignNumeric)
                condition = LexicalStatus::LexicalNumericValue1, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignDollar)
                condition = LexicalStatus::LexicalHexValue, lexicalTokens.back().type = LexicalType::ValueHexNumber, lexicalTokens.back().value.push_back(i->symbol);
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::LexicalNumericValue1:
            if (i->type == TransliterationType::SignExponent)
                condition = LexicalStatus::LexicalExponentValue1, lexicalTokens.back().type = LexicalType::ValueExponentNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignNumeric)
                condition = LexicalStatus::LexicalNumericValue1, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignPoint)
                condition = LexicalStatus::LexicalNumericValue2, lexicalTokens.back().type = LexicalType::ValueFloatNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                condition = LexicalStatus::LexicalFinish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::LexicalNumericValue2:
            if (i->type == TransliterationType::SignExponent)
                condition = LexicalStatus::LexicalExponentValue1, lexicalTokens.back().type = LexicalType::ValueExponentNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignNumeric)
                condition = LexicalStatus::LexicalNumericValue2, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                condition = LexicalStatus::LexicalFinish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::LexicalHexValue:
            if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::SignNumeric || i->type == TransliterationType::SignHexLetter)
                condition = LexicalStatus::LexicalHexValue, lexicalTokens.back().type = LexicalType::ValueHexNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                condition = LexicalStatus::LexicalFinish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::LexicalExponentValue1:
            if (i->type == TransliterationType::SignNumeric || i->type == TransliterationType::SignPM)
                condition = LexicalStatus::LexicalExponentValue2, lexicalTokens.back().type = LexicalType::ValueExponentNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                condition = LexicalStatus::LexicalFinish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::LexicalExponentValue2:
            if (i->type == TransliterationType::SignNumeric)
                condition = LexicalStatus::LexicalExponentValue2, lexicalTokens.back().type = LexicalType::ValueExponentNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                condition = LexicalStatus::LexicalFinish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::LexicalSemicolon:
            if(i->type == TransliterationType::SignWhiteSpace)
                continue;;
            if (i->type == TransliterationType::SignSemicolon)
                condition = LexicalStatus::LexicalFinish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::LexicalFinish:
            if (i->type != TransliterationType::SignWhiteSpace)
                status = SequenceStatus::Rejected;
            break;
        }

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

    return lexicalTokens;
}

LexicalUnit::~LexicalUnit()
{
}
