#pragma once


#include "SequenceStatus.h"
#include "Atom.h"
#include "vector"
#include "LexicalToken.h"
#include <iostream>
using namespace  std;

namespace Test
{
    static void pushMain(std::string & source)
    {
        printf("--------------------------------------------------\n");
        printf("Testing sequence \"%s\"\n", source.c_str());
    }
    template <typename T>
    static void pushIn(SequenceStatus::SequenceStatus & status)
    {
        printf("\nModule: %s\n", typeid(T).name());
    }
    static void pushOut(SequenceStatus::SequenceStatus & status)
    {
        printf("   Output status: %s\n", SequenceStatus::toString[status].c_str());
    }

    static void pushOut(SequenceStatus::SequenceStatus & status, vector<Atom> & sequence)
    {
        for (int i = 0; i < sequence.size(); ++i)
            cout << "      Atom "<< i + 1 << " = ("<< sequence[i].symbol <<", "<< TransliterationType::toString[sequence[i].type] << ")\n";
        pushOut(status);
    }
    static void pushOut(SequenceStatus::SequenceStatus & status,vector<LexicalToken> lexicalTokens) 
    {
        if (lexicalTokens.size()> 1)
            for (int i = 0; i < lexicalTokens.size(); ++i)
                printf("      Token %d = (%s ,%s)\n",i + 1 , lexicalTokens[i].value.c_str(), LexicalType::toString[lexicalTokens[i].type].c_str());
        pushOut(status);
    }
}
