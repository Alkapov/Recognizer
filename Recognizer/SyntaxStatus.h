#pragma once

enum SyntaxStatus
{
    SyntaxConstKeyword,
    SyntaxIdentifier,
    SyntaxEqual,
    SyntaxValue,
    SyntaxSemicolon,
    SyntaxFinish
};