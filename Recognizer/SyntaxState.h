#pragma once

namespace SyntaxState 
{
    enum SyntaxState
    {
        ConstKeyword,
        Identifier,
        Equal,
        Value,
        Semicolon,
        Finish
    };
}