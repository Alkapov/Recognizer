#pragma once

enum LexicalStatus
{             
    LexicalStart,
    LexicalKeyword,
    LexicalWhiteSpace1,
    LexicalIdentifier,
    LexicalWhiteSpace2,
    LexicalUndenifiedValue,
    LexicalStringValue,
    LexicalUndenifiedNumericValue,
    LexicalNumericValue1,
    LexicalNumericValue2,
    LexicalHexValue,
    LexicalExponentValue1,
    LexicalExponentValue2,
    LexicalSemicolon,
    LexicalFinish
};