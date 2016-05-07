#include "LexicalUnit.h"
#include "LexicalState.h"
#include "LexicalType.h"

#include "Test.h"


LexicalUnit::LexicalUnit()
{

}

vector<LexicalToken> LexicalUnit::Analize(vector<Atom> & sequence, SequenceStatus::SequenceStatus & status)
{         

#if _DEBUG
    Test::pushIn<LexicalUnit>(status);

#endif

    vector<LexicalToken> lexicalTokens(1);
    LexicalState::LexicalState state = LexicalState::Start;
    for (vector<Atom>::iterator i = sequence.begin(); i != sequence.end() && status != SequenceStatus::Rejected; ++i)
        switch (state)
        {
        case LexicalState::Start:
            if (i->type == TransliterationType::SignWhiteSpace)
                continue;
            else if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::HexLetter || i->type == TransliterationType::Letter)
                state = LexicalState::Keyword, lexicalTokens.back().type = LexicalType::Keyword, lexicalTokens.back().value.push_back(i->symbol);
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalState::Keyword:
            if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::HexLetter || i->type == TransliterationType::Letter)
                lexicalTokens.back().type = LexicalType::Keyword, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignWhiteSpace)
                state = LexicalState::WhiteSpace1, lexicalTokens.push_back(LexicalToken());
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalState::WhiteSpace1:
            if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::HexLetter || i->type == TransliterationType::Letter)
               state = LexicalState::LexicalIdentifier, lexicalTokens.back().type = LexicalType::Identifier, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignWhiteSpace)
                continue;
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalState::LexicalIdentifier:
            if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::HexLetter || i->type == TransliterationType::Letter || i->type == TransliterationType::Numeric || i->type == TransliterationType::SignUnderscope)
                lexicalTokens.back().type = LexicalType::Identifier, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignWhiteSpace)
                state = LexicalState::WhiteSpace2;
            else if (i->type == TransliterationType::SignEqual)
                state = LexicalState::UndenifiedValue, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Equal)), lexicalTokens.push_back(LexicalToken());
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalState::WhiteSpace2:
            if (i->type == TransliterationType::SignWhiteSpace)
                continue;
            else if (i->type == TransliterationType::SignEqual)
                state = LexicalState::UndenifiedValue, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Equal)), lexicalTokens.push_back(LexicalToken());
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalState::UndenifiedValue:
            if (i->type == TransliterationType::Numeric)
                state = LexicalState::NumericValue1, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignDollar)
                state = LexicalState::HexValue, lexicalTokens.back().type = LexicalType::ValueHexNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignApostrophe)
                state = LexicalState::StringValue, lexicalTokens.back().type = LexicalType::ValueString, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignPM)
                state = LexicalState::UndenifiedNumericValue, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignWhiteSpace)
                continue;
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalState::StringValue:
            if (i->type == TransliterationType::SignApostrophe)
                state = LexicalState::Semicolon, lexicalTokens.back().value.push_back(i->symbol);
            else
                lexicalTokens.back().type = LexicalType::ValueString, lexicalTokens.back().value.push_back(i->symbol);
            break;
        case LexicalState::UndenifiedNumericValue:
            if (i->type == TransliterationType::Numeric)
                state = LexicalState::NumericValue1, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignDollar)
                state = LexicalState::HexValue, lexicalTokens.back().type = LexicalType::ValueHexNumber, lexicalTokens.back().value.push_back(i->symbol);
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalState::NumericValue1:
            if (i->type == TransliterationType::SignExponent)
                state = LexicalState::ExponentValue1, lexicalTokens.back().type = LexicalType::ValueExponentNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::Numeric)
                state = LexicalState::NumericValue1, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignPoint)
                state = LexicalState::NumericValue2, lexicalTokens.back().type = LexicalType::ValueFloatNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                state = LexicalState::Finish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalState::NumericValue2:
            if (i->type == TransliterationType::SignExponent)
                state = LexicalState::ExponentValue1, lexicalTokens.back().type = LexicalType::ValueExponentNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::Numeric)
                state = LexicalState::NumericValue2, lexicalTokens.back().type = LexicalType::ValueDecimalNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                state = LexicalState::Finish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalState::HexValue:
            if (i->type == TransliterationType::SignExponent || i->type == TransliterationType::Numeric || i->type == TransliterationType::HexLetter)
                state = LexicalState::HexValue, lexicalTokens.back().type = LexicalType::ValueHexNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                state = LexicalState::Finish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalState::ExponentValue1:
            if (i->type == TransliterationType::Numeric || i->type == TransliterationType::SignPM)
                state = LexicalState::ExponentValue2, lexicalTokens.back().type = LexicalType::ValueExponentNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                state = LexicalState::Finish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalState::ExponentValue2:
            if (i->type == TransliterationType::Numeric)
                state = LexicalState::ExponentValue2, lexicalTokens.back().type = LexicalType::ValueExponentNumber, lexicalTokens.back().value.push_back(i->symbol);
            else if (i->type == TransliterationType::SignSemicolon)
                state = LexicalState::Finish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalState::Semicolon:
            if(i->type == TransliterationType::SignWhiteSpace)
                continue;;
            if (i->type == TransliterationType::SignSemicolon)
                state = LexicalState::Finish, lexicalTokens.push_back(LexicalToken(i->symbol, LexicalType::Semicolon));
            else
                status = SequenceStatus::Rejected;
            break;
        case LexicalState::Finish:
            if (i->type != TransliterationType::SignWhiteSpace)
                status = SequenceStatus::Rejected;
            break;
        }

#if _DEBUG
        Test::pushOut(status, lexicalTokens);
#endif

    return lexicalTokens;
}

LexicalUnit::~LexicalUnit()
{
}
