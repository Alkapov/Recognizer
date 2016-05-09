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
        UnidentifiedValue,
        StringValue,
        UnidentifiedNumericValue,
        NumericValue1,
        NumericValue2,
        HexValue,
        ExponentValue1,
        ExponentValue2,
        Semicolon,
        Finish
    };
}