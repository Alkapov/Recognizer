#include "SyntaxUnit.h"



SyntaxUnit::SyntaxUnit()
{

}

void SyntaxUnit::Verificate(vector<LexicalToken> & lexicalTokens, SequenceStatus & status)
{
    SyntaxStatus condition = SyntaxStatus::ConstKeyword;
    for (vector<LexicalToken>::iterator i = lexicalTokens.begin(); i != lexicalTokens.end() && status != SequenceStatus::Rejected; ++i)
        switch (condition)
        {
        case ConstKeyword:
            if (i->type == LexicalType::KeywordConst)
                condition = SyntaxStatus::Identifier;
            else
                status = SequenceStatus::Rejected;
            break;
        case Identifier:
            if (i->type == LexicalType::Identifier)
                condition = SyntaxStatus::Equal;
            else
                status = SequenceStatus::Rejected;
            break;
        case Equal:
            if (i->type == LexicalType::Equal)
                condition = SyntaxStatus::Value;
            else
                status = SequenceStatus::Rejected;
            break;
        case Value:
            if (i->type == LexicalType::ValueDecimalNumber || i->type == LexicalType::ValueExponentNumber || i->type == LexicalType::ValueFloatNumber || i->type == LexicalType::ValueHexNumber || i->type == LexicalType::ValueString)
                condition = SyntaxStatus::Semicolon;
            else
                status = SequenceStatus::Rejected;
            break;
        case Semicolon: 
            if (i->type == LexicalType::Semicolon)
                condition = SyntaxStatus::Finish;
            else    
                status = SequenceStatus::Rejected;
            break;
        case Finish:
            status = SequenceStatus::Rejected;
            break;
        }
    if (condition == SyntaxStatus::Finish)
        status = SequenceStatus::Accepted;
    else
        status = SequenceStatus::Rejected;
}


SyntaxUnit::~SyntaxUnit()
{
}
