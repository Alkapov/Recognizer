#pragma once

namespace LexicalState 
{
    enum LexicalState
    {
        Start,
        Keyword,
        WhiteSpace1,
        Identifier,
        WhiteSpace2,
        UndenifiedValue,
        StringValue,
        UndenifiedNumericValue,
        NumericValue1,
        NumericValue2,
        HexValue,
        ExponentValue1,
        ExponentValue2,
        Semicolon,
        Finish
    };
}