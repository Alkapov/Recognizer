#include "LexicalUnit.h"

LexicalUnit::LexicalUnit()
{

}



vector<LexicalToken> LexicalUnit::Analize(vector<Atom> & sequence, SequenceStatus & status)
{
    //vector<string> outsequence(0);
    //LexicalStatus status = LexicalStatus::Start;
    //bool error = false;
    //for (vector<Atom>::iterator i = sequence.begin(); i != sequence.end() && !error; ++i)
    //{
    //    switch (status)
    //    {
    //    case LexicalStatus::Start:
    //        if (i->type == TransliterationType::Space)
    //            continue;
    //        else if (i->type == TransliterationType::Letter || i->type == TransliterationType::Exponent || i->type == TransliterationType::Hex)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Keyword;
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::Keyword:
    //        if (i->type == TransliterationType::Letter || i->type == TransliterationType::Exponent || i->type == TransliterationType::Hex)
    //            outsequence.back().push_back(i->symbol);
    //        else if (i->type == TransliterationType::Space)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space1;
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::Space1:
    //        if (i->type == TransliterationType::Letter || i->type == TransliterationType::Exponent || i->type == TransliterationType::Hex)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Identifier;
    //        else if (i->type == TransliterationType::Space)
    //            outsequence.back().push_back(i->symbol);
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::Space2:
    //        if (i->type == TransliterationType::Space)
    //            outsequence.back().push_back(i->symbol);
    //        else if (i->type == TransliterationType::EquallySign)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Equally;
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::Space3:
    //        if (i->type == TransliterationType::Apostrophe)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::StringValue;
    //        else if (i->type == TransliterationType::Sign)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::SignValue;
    //        else if (i->type == TransliterationType::Space)
    //            outsequence.back().push_back(i->symbol);
    //        else if (i->type == TransliterationType::Letter || i->type == TransliterationType::Exponent || i->type == TransliterationType::Hex)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::IdentifierValue;
    //        else if (i->type == TransliterationType::Numeric)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::DecimalNumeric;
    //        else if (i->type == TransliterationType::DollarSign)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::HexNumeric;
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::Space4:
    //        if (i->type == TransliterationType::Numeric)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::DecimalNumeric;
    //        else if (i->type == TransliterationType::DollarSign)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::HexNumeric;
    //        else if (i->type == TransliterationType::Space)
    //            outsequence.back().push_back(i->symbol);
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::Space5:
    //        if (i->type == TransliterationType::Semicolon)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Finish;
    //        else if (i->type == TransliterationType::Space)
    //            outsequence.back().push_back(i->symbol);
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::Identifier:
    //        if (i->type == TransliterationType::Space)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space2;
    //        else if (i->type == TransliterationType::EquallySign)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Equally;
    //        else if (i->type == TransliterationType::Letter || i->type == TransliterationType::Numeric || i->type == TransliterationType::DollarSign || i->type == TransliterationType::Exponent || i->type == TransliterationType::Underscore || i->type == TransliterationType::Hex)
    //            outsequence.back().push_back(i->symbol);
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::Equally:
    //        if (i->type == TransliterationType::Apostrophe)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::StringValue;
    //        else if (i->type == TransliterationType::Sign)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::SignValue;
    //        else if (i->type == TransliterationType::Space)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space3;
    //        else if (i->type == TransliterationType::Letter || i->type == TransliterationType::Exponent || i->type == TransliterationType::Hex)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::IdentifierValue;
    //        else if (i->type == TransliterationType::Numeric)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::DecimalNumeric;
    //        else if (i->type == TransliterationType::DollarSign)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::HexNumeric;
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::StringValue:
    //        if (i->type == TransliterationType::Apostrophe)
    //            outsequence.back().push_back(i->symbol), status = LexicalStatus::ApostropheValue;
    //        else
    //            outsequence.back().push_back(i->symbol);
    //        break;
    //    case LexicalStatus::SignValue:
    //        if (i->type == TransliterationType::Numeric)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::DecimalNumeric;
    //        else if (i->type == TransliterationType::Space)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space4;
    //        else if (i->type == TransliterationType::DollarSign)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::HexNumeric;
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::IdentifierValue:
    //        if (i->type == TransliterationType::Space)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space5;
    //        else if (i->type == TransliterationType::Semicolon)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Finish;
    //        else if (i->type == TransliterationType::Letter || i->type == TransliterationType::Numeric || i->type == TransliterationType::DollarSign || i->type == TransliterationType::Exponent || i->type == TransliterationType::Underscore || i->type == TransliterationType::Hex)
    //            outsequence.back().push_back(i->symbol);
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::ApostropheValue:
    //        if (i->type == TransliterationType::Space)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space5;
    //        else if (i->type == TransliterationType::Semicolon)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Finish;
    //        else if (i->type == TransliterationType::Apostrophe)
    //            outsequence.back().push_back(i->symbol), status = LexicalStatus::StringValue;
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::HexNumeric:
    //        if (i->type == TransliterationType::Space)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space5;
    //        else if (i->type == TransliterationType::Semicolon)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Finish;
    //        else if (i->type == TransliterationType::Numeric || i->type == TransliterationType::Exponent || i->type == TransliterationType::Hex)
    //            outsequence.back().push_back(i->symbol);
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::DecimalNumeric:
    //        if (i->type == TransliterationType::Space)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space5;
    //        else if (i->type == TransliterationType::Semicolon)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Finish;
    //        else if (i->type == TransliterationType::Numeric)
    //            outsequence.back().push_back(i->symbol);
    //        else if (i->type == TransliterationType::Exponent)
    //            outsequence.back().push_back(i->symbol), status = LexicalStatus::ExpSign;
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::ExpNumeric:
    //        if (i->type == TransliterationType::Space)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space5;
    //        else if (i->type == TransliterationType::Semicolon)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Finish;
    //        else if (i->type == TransliterationType::Numeric)
    //            outsequence.back().push_back(i->symbol);
    //        else
    //            error = true;
    //        break;
    //    case LexicalStatus::ExpSign:
    //        if (i->type == TransliterationType::Space)
    //            outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space5;
    //        else if (i->type == TransliterationType::Sign || i->type == TransliterationType::Numeric)
    //            outsequence.back().push_back(i->symbol), status = LexicalStatus::ExpNumeric;
    //        else
    //            error = true;
    //        break;
    //    break;
    //    case LexicalStatus::Finish:
    //        if (i->type == TransliterationType::Semicolon)
    //            outsequence.back().push_back(i->symbol);
    //        else
    //            error = true;
    //        break;
    //    }
    //}
    //return outsequence;
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

}

LexicalUnit::~LexicalUnit()
{
}
