#include "LexicalUnit.h"

LexicalUnit::LexicalUnit()
{

}

vector<string> LexicalUnit::Analize(vector<Atom> sequence)
{
    vector<string> outsequence(0);
    LexicalStatus status = LexicalStatus::Start;
    bool error = false;
    for (vector<Atom>::iterator i = sequence.begin(); i != sequence.end() && !error; ++i)
    {
        switch (status)
        {
        case LexicalStatus::Start:
            if (i->type == TransliterationType::Space)
                continue;
            else if (i->type == TransliterationType::Letter || i->type == TransliterationType::Exponent || i->type == TransliterationType::Hex)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Keyword;
            else
                error = true;
            break;
        case LexicalStatus::Keyword:
            if (i->type == TransliterationType::Letter || i->type == TransliterationType::Exponent || i->type == TransliterationType::Hex)
                outsequence.back().push_back(i->symbol);
            else if (i->type == TransliterationType::Space)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space1;
            else
                error = true;
            break;
        case LexicalStatus::Space1:
            if (i->type == TransliterationType::Letter || i->type == TransliterationType::Exponent || i->type == TransliterationType::Hex)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Identifier;
            else if (i->type == TransliterationType::Space)
                outsequence.back().push_back(i->symbol);
            else
                error = true;
            break;
        case LexicalStatus::Space2:
            if (i->type == TransliterationType::Space)
                outsequence.back().push_back(i->symbol);
            else if (i->type == TransliterationType::EquallySign)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Equally;
            else
                error = true;
            break;
        case LexicalStatus::Space3:
            if (i->type == TransliterationType::Apostrophe)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::StringValue;
            else if (i->type == TransliterationType::Sign)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::SignValue;
            else if (i->type == TransliterationType::Space)
                outsequence.back().push_back(i->symbol);
            else if (i->type == TransliterationType::Letter || i->type == TransliterationType::Exponent || i->type == TransliterationType::Hex)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::IdentifierValue;
            else if (i->type == TransliterationType::Numeric)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::DecimalNumeric;
            else if (i->type == TransliterationType::DollarSign)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::HexNumeric;
            else
                error = true;
            break;
        case LexicalStatus::Space4:
            if (i->type == TransliterationType::Numeric)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::DecimalNumeric;
            else if (i->type == TransliterationType::DollarSign)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::HexNumeric;
            else if (i->type == TransliterationType::Space)
                outsequence.back().push_back(i->symbol);
            else
                error = true;
            break;
        case LexicalStatus::Space5:
            if (i->type == TransliterationType::Semicolon)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Finish;
            else if (i->type == TransliterationType::Space)
                outsequence.back().push_back(i->symbol);
            else
                error = true;
            break;
        case LexicalStatus::Identifier:
            if (i->type == TransliterationType::Space)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space2;
            else if (i->type == TransliterationType::EquallySign)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Equally;
            else if (i->type == TransliterationType::Letter || i->type == TransliterationType::Numeric || i->type == TransliterationType::DollarSign || i->type == TransliterationType::Exponent || i->type == TransliterationType::Underscore || i->type == TransliterationType::Hex)
                outsequence.back().push_back(i->symbol);
            else
                error = true;
            break;
        case LexicalStatus::Equally:
            if (i->type == TransliterationType::Apostrophe)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::StringValue;
            else if (i->type == TransliterationType::Sign)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::SignValue;
            else if (i->type == TransliterationType::Space)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space3;
            else if (i->type == TransliterationType::Letter || i->type == TransliterationType::Exponent || i->type == TransliterationType::Hex)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::IdentifierValue;
            else if (i->type == TransliterationType::Numeric)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::DecimalNumeric;
            else if (i->type == TransliterationType::DollarSign)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::HexNumeric;
            else
                error = true;
            break;
        case LexicalStatus::StringValue:
            if (i->type == TransliterationType::Apostrophe)
                outsequence.back().push_back(i->symbol), status = LexicalStatus::ApostropheValue;
            else
                outsequence.back().push_back(i->symbol);
            break;
        case LexicalStatus::SignValue:
            if (i->type == TransliterationType::Numeric)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::DecimalNumeric;
            else if (i->type == TransliterationType::Space)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space4;
            else if (i->type == TransliterationType::DollarSign)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::HexNumeric;
            else
                error = true;
            break;
        case LexicalStatus::IdentifierValue:
            if (i->type == TransliterationType::Space)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space5;
            else if (i->type == TransliterationType::Semicolon)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Finish;
            else if (i->type == TransliterationType::Letter || i->type == TransliterationType::Numeric || i->type == TransliterationType::DollarSign || i->type == TransliterationType::Exponent || i->type == TransliterationType::Underscore || i->type == TransliterationType::Hex)
                outsequence.back().push_back(i->symbol);
            else
                error = true;
            break;
        case LexicalStatus::ApostropheValue:
            if (i->type == TransliterationType::Space)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space5;
            else if (i->type == TransliterationType::Semicolon)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Finish;
            else if (i->type == TransliterationType::Apostrophe)
                outsequence.back().push_back(i->symbol), status = LexicalStatus::StringValue;
            else
                error = true;
            break;
        case LexicalStatus::HexNumeric:
            if (i->type == TransliterationType::Space)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space5;
            else if (i->type == TransliterationType::Semicolon)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Finish;
            else if (i->type == TransliterationType::Numeric || i->type == TransliterationType::Exponent || i->type == TransliterationType::Hex)
                outsequence.back().push_back(i->symbol);
            else
                error = true;
            break;
        case LexicalStatus::DecimalNumeric:
            if (i->type == TransliterationType::Space)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space5;
            else if (i->type == TransliterationType::Semicolon)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Finish;
            else if (i->type == TransliterationType::Numeric)
                outsequence.back().push_back(i->symbol);
            else if (i->type == TransliterationType::Exponent)
                outsequence.back().push_back(i->symbol), status = LexicalStatus::ExpSign;
            else
                error = true;
            break;
        case LexicalStatus::ExpNumeric:
            if (i->type == TransliterationType::Space)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space5;
            else if (i->type == TransliterationType::Semicolon)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Finish;
            else if (i->type == TransliterationType::Numeric)
                outsequence.back().push_back(i->symbol);
            else
                error = true;
            break;
        case LexicalStatus::ExpSign:
            if (i->type == TransliterationType::Space)
                outsequence.push_back(string(1, i->symbol)), status = LexicalStatus::Space5;
            else if (i->type == TransliterationType::Sign || i->type == TransliterationType::Numeric)
                outsequence.back().push_back(i->symbol), status = LexicalStatus::ExpNumeric;
            else
                error = true;
            break;
        break;
        case LexicalStatus::Finish:
            if (i->type == TransliterationType::Semicolon)
                outsequence.back().push_back(i->symbol);
            else
                error = true;
            break;
        }
    }
    return outsequence;
}

LexicalUnit::~LexicalUnit()
{
}
