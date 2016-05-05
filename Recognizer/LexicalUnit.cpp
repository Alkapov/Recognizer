#include "LexicalUnit.h"

LexicalUnit::LexicalUnit()
{

}



vector<LexicalToken> LexicalUnit::Analize(vector<Atom> & sequence, SequenceStatus & status)
{
    vector<LexicalToken> lexicalTokens(1);
    LexicalStatus condition = LexicalStatus::Start;
    for (vector<Atom>::iterator i = sequence.begin(); i != sequence.end() && status != SequenceStatus::Rejected; ++i)
        switch (condition)
        {
        case LexicalStatus::Start:
            if (i->type == TransliterationType::SignWhiteSpace)
                continue;
            else if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::SignHexLetter || i->type == TransliterationType::SignLetter)
                condition = LexicalStatus::Keyword, lexicalTokens.back().type = LexicalType::Keyword, lexicalTokens.back().value.push_back(i->symbol);
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::Keyword:
            if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::SignHexLetter || i->type == TransliterationType::SignLetter)
                lexicalTokens.back().type = LexicalType::Keyword, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignWhiteSpace)
                condition = LexicalStatus::WhiteSpace1, lexicalTokens.push_back(LexicalToken());
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::WhiteSpace1:
            if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::SignHexLetter || i->type == TransliterationType::SignLetter)
                lexicalTokens.back().type = LexicalType::Identifier, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignWhiteSpace)
                continue;
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::Identifier:
            if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::SignHexLetter || i->type == TransliterationType::SignLetter || i->type == TransliterationType::SignNumeric || i->type == TransliterationType::SignUnderscope)
                lexicalTokens.back().type = LexicalType::Identifier, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignWhiteSpace)
                condition = LexicalStatus::WhiteSpace2;
            else if (i->type == TransliterationType::SignEqual)
                condition = LexicalStatus::UndenifiedValue, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Equal)), lexicalTokens.push_back(LexicalToken());
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::WhiteSpace2:
            if (i->type == TransliterationType::SignWhiteSpace)
                continue;
            else if (i->type == TransliterationType::SignEqual)
                condition = LexicalStatus::UndenifiedValue, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Equal)), lexicalTokens.push_back(LexicalToken());
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::UndenifiedValue:
            if (i->type == TransliterationType::SignNumeric)
                condition = LexicalStatus::NumericValue1, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignDollar)
                condition = LexicalStatus::HexValue, lexicalTokens.back().type = LexicalType::ValueHexNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignApostrophe)
                condition = LexicalStatus::StringValue, lexicalTokens.back().type = LexicalType::ValueString, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignPM)
                condition = LexicalStatus::UndenifiedNumericValue, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignWhiteSpace)
                continue;
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::StringValue:
            if (i->type == TransliterationType::SignApostrophe)
                condition = LexicalStatus::Semicolon, lexicalTokens.back().value.push_back(i->symbol);
            else
                lexicalTokens.back().type = LexicalType::ValueString, lexicalTokens.back().value.push_back(i->symbol);
            break;
        case LexicalStatus::UndenifiedNumericValue:
            if (i->type == TransliterationType::SignNumeric)
                condition = LexicalStatus::NumericValue1, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignDollar)
                condition = LexicalStatus::HexValue, lexicalTokens.back().type = LexicalType::ValueHexNumber, lexicalTokens.back().value.push_back(i->symbol);
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::NumericValue1:
            if (i->type == TransliterationType::SignExponent)
                condition = LexicalStatus::ExponentValue1, lexicalTokens.back().type = LexicalType::ValueExponentNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignNumeric)
                condition = LexicalStatus::NumericValue1, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignPoint)
                condition = LexicalStatus::NumericValue2, lexicalTokens.back().type = LexicalType::ValueFloatNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                condition = LexicalStatus::Finish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::NumericValue2:
            if (i->type == TransliterationType::SignExponent)
                condition = LexicalStatus::ExponentValue1, lexicalTokens.back().type = LexicalType::ValueExponentNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignNumeric)
                condition = LexicalStatus::NumericValue2, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                condition = LexicalStatus::Finish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::HexValue:
            if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::SignLetter || i->type == TransliterationType::SignNumeric)
                condition = LexicalStatus::HexValue, lexicalTokens.back().type = LexicalType::ValueHexNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                condition = LexicalStatus::Finish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::ExponentValue1:
            if (i->type == TransliterationType::SignNumeric || i->type == TransliterationType::SignPM)
                condition = LexicalStatus::ExponentValue2, lexicalTokens.back().type = LexicalType::ValueExponentNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                condition = LexicalStatus::Finish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::ExponentValue2:
            if (i->type == TransliterationType::SignNumeric)
                condition = LexicalStatus::ExponentValue2, lexicalTokens.back().type = LexicalType::ValueExponentNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                condition = LexicalStatus::Finish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::Semicolon:
            if (i->type == TransliterationType::SignSemicolon)
                condition = LexicalStatus::Finish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalStatus::Finish:
            if (i->type != TransliterationType::SignWhiteSpace)
                status = SequenceStatus::Rejected;
            break;
        }
        //TODO: Test it!  
        return lexicalTokens;
}

LexicalUnit::~LexicalUnit()
{
}
