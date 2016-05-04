#pragma once

enum LexicalStatus
{
    Start, 
    Keyword, 
    Space1, 
    Space2, 
    Space3, 
    Space4, 
    Space5, 
    Identifier, 
    Equally, 
    StringValue, 
    SignValue, 
    IdentifierValue, 
    ApostropheValue, 
    HexNumeric, 
    DecimalNumeric, 
    ExpNumeric, 
    ExpSign, 
    Finish
};