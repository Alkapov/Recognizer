#include "LexicalUnit.h"

LexicalUnit::LexicalUnit()
{

}



vector<LexicalToken> LexicalUnit::Analize(vector<Atom> & sequence, SequenceStatus & status)
{
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
                lexicalTokens.back().type = LexicalType::Identifier, lexicalTokens.back().value.push_back(i->symbol);
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
            if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::SignLetter || i->type == TransliterationType::SignNumeric)
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
        return lexicalTokens;
}

LexicalUnit::~LexicalUnit()
{
}
