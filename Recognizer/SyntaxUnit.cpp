#include "SyntaxUnit.h"
#include "SyntaxStatus.h"


SyntaxUnit::SyntaxUnit()
{

}

void SyntaxUnit::Verificate(vector<LexicalToken> & lexicalTokens, SequenceStatus & status)
{
#if _DEBUG
    printf("\nModule: SyntaxUnit.cpp\n");
    printf("   Input status: %s\n", status == SequenceStatus::Accepted ? "Accepted" : (status == SequenceStatus::Rejected ? "Rejected" : "Unidentified"));
#endif
    SyntaxStatus condition = SyntaxStatus::SyntaxConstKeyword;
    for (vector<LexicalToken>::iterator i = lexicalTokens.begin(); i != lexicalTokens.end() && status != SequenceStatus::Rejected; ++i)
        switch (condition)
        {
        case SyntaxStatus::SyntaxConstKeyword:
            if (i->type == LexicalType::KeywordConst)
                condition = SyntaxStatus::SyntaxIdentifier;
            else
                status = SequenceStatus::Rejected;
            break;
        case SyntaxStatus::SyntaxIdentifier:
            if (i->type == LexicalType::Identifier)
                condition = SyntaxStatus::SyntaxEqual;
            else
                status = SequenceStatus::Rejected;
            break;
        case SyntaxStatus::SyntaxEqual:
            if (i->type == LexicalType::Equal)
                condition = SyntaxStatus::SyntaxValue;
            else
                status = SequenceStatus::Rejected;
            break;
        case SyntaxStatus::SyntaxValue:
            if (i->type == LexicalType::ValueDecimalNumber || i->type == LexicalType::ValueExponentNumber || i->type == LexicalType::ValueFloatNumber || i->type == LexicalType::ValueHexNumber || i->type == LexicalType::ValueString)
                condition = SyntaxStatus::SyntaxSemicolon;
            else
                status = SequenceStatus::Rejected;
            break;
        case SyntaxStatus::SyntaxSemicolon: 
            if (i->type == LexicalType::Semicolon)
                condition = SyntaxStatus::SyntaxFinish;
            else    
                status = SequenceStatus::Rejected;
            break;
        case SyntaxStatus::SyntaxFinish:
            status = SequenceStatus::Rejected;
            break;
        }
    if (condition == SyntaxStatus::SyntaxFinish)
        status = SequenceStatus::Accepted;
    else
        status = SequenceStatus::Rejected;
#if _DEBUG
    //TODO: Delme 

    printf("   Result: %s\n", status == SequenceStatus::Accepted ? "Accepted" : (status == SequenceStatus::Rejected ? "Rejected" : "Unidentified"));
#endif

}


SyntaxUnit::~SyntaxUnit()
{
}
