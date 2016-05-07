#pragma once 

#include "stdafx.h"

namespace TransliterationType
{
    enum TransliterationType
    {
        SignExponent,
        HexLetter,
        Letter,
        Numeric,
        SignDollar,
        SignApostrophe,
        SignSemicolon,
        SignUnderscope,
        SignPM,
        SignWhiteSpace,
        SignEqual,
        SignPoint,
        Error
    };
#if _DEBUG
    const vector<string> toString = 
    {
        "SignExponent",
        "HexLetter",
        "Letter",
        "Numeric",
        "SignDollar",
        "SignApostrophe",
        "SignSemicolon",
        "SignUnderscope",
        "SignPM",
        "SignWhiteSpace",
        "SignEqual",
        "SignPoint",
        "Error"
    };
#endif

}
