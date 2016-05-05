#pragma once

enum SyntaxStatus
{
    ConstKeyword,
    Identifier,
    Equal,
    Value,
    Semicolon,
    Finish
};