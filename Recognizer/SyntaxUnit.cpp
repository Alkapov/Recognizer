#include "SyntaxUnit.h"
#include "SyntaxState.h"

#include "Test.h"

SyntaxUnit::SyntaxUnit()
{

}

void SyntaxUnit::Verificate(vector<LexicalToken> & lexicalTokens, SequenceStatus::SequenceStatus & status)
{
#if _DEBUG
    Test::pushIn<SyntaxUnit>(status);
#endif

    SyntaxState::SyntaxState state = SyntaxState::ConstKeyword;
    for (vector<LexicalToken>::iterator i = lexicalTokens.begin(); i != lexicalTokens.end() && status != SequenceStatus::Rejected; ++i)
        switch (state)
        {
        case SyntaxState::ConstKeyword:
            if (i->type == LexicalType::KeywordConst)
                state = SyntaxState::Identifier;
            else
                status = SequenceStatus::Rejected;
            break;
        case SyntaxState::Identifier:
            if (i->type == LexicalType::Identifier)
                state = SyntaxState::Equal;
            else
                status = SequenceStatus::Rejected;
            break;
        case SyntaxState::Equal:
            if (i->type == LexicalType::Equal)
                state = SyntaxState::Value;
            else
                status = SequenceStatus::Rejected;
            break;
        case SyntaxState::Value:
            if (i->type == LexicalType::ValueDecimalNumber || i->type == LexicalType::ValueExponentNumber || i->type == LexicalType::ValueFloatNumber || i->type == LexicalType::ValueHexNumber || i->type == LexicalType::ValueString)
                state = SyntaxState::Semicolon;
            else
                status = SequenceStatus::Rejected;
            break;
        case SyntaxState::Semicolon: 
            if (i->type == LexicalType::Semicolon)
                state = SyntaxState::Finish;
            else    
                status = SequenceStatus::Rejected;
            break;
        case SyntaxState::Finish:
            status = SequenceStatus::Rejected;
            break;
        }
    if (state == SyntaxState::Finish)
        status = SequenceStatus::Accepted;
    else
        status = SequenceStatus::Rejected;
#if _DEBUG

    printf("   Result: %s\n", status == SequenceStatus::Accepted ? "Accepted" : (status == SequenceStatus::Rejected ? "Rejected" : "Unidentified"));
#endif

}


SyntaxUnit::~SyntaxUnit()
{
}
