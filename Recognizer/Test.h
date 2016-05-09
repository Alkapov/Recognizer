#pragma once

#include "stdafx.h"

#include "SequenceStatus.h"
#include "Atom.h"
#include "LexicalToken.h"
#include "Recognizer.h"
#if _DEBUG

#define MODULETEST 0 

namespace Test
{
    static vector<string> readTests(string fileName)
    {

        vector<string> sequences;
        ifstream file(fileName);
        string str;
        while (getline(file, str))
            sequences.push_back(str);
        file.close();
        return sequences;
    }

    static void clear()
    {
        freopen("input.txt", "w", stdout);
        cout << "const real a = 2;" << endl;
        fclose(stdout);
    }

    static void Run()
    {
        freopen("output.txt", "w", stdout);
        Recognizer recognizer;
        vector<string> source = readTests("input.txt");
        for (vector<string>::iterator i = source.begin(); i != source.end(); ++i)           
            if (recognizer.Check(*i))
                printf("Accepted\n");
            else
                printf("Rejected\n");
        fclose(stdout);
    }
    

    static void pushMain(std::string & source)
    {
#if MODULETEST
        printf("--------------------------------------------------\n");
        printf("Testing sequence \"%s\"\n", source.c_str());
#endif
    }

    template <typename T>
    static void pushIn(SequenceStatus::SequenceStatus & status)
    {
#if MODULETEST
        printf("\nModule: %s\n", typeid(T).name());
#endif
    }
 
    static void pushOut(SequenceStatus::SequenceStatus & status)
    {
#if MODULETEST
        printf("   Output status: %s\n", SequenceStatus::toString[status].c_str());
#endif
    }

    static void pushOut(SequenceStatus::SequenceStatus & status, vector<Atom> & sequence)
    {
#if MODULETEST
        printf("      <Type> # = (<Symbol>, <TransliterationType>)\n");
        for (int i = 0; i < sequence.size(); ++i)
            printf("      Atom %d  = (%c, %s)\n", i + 1, sequence[i].symbol, TransliterationType::toString[sequence[i].type].c_str());
        pushOut(status);
#endif
    }
    static void pushOut(SequenceStatus::SequenceStatus & status,vector<LexicalToken> lexicalTokens) 
    {
#if MODULETEST
        printf("      <Type> # = (<Value>, <LexicalType>)\n");
        if (lexicalTokens.size()> 1)
            for (int i = 0; i < lexicalTokens.size(); ++i)
                printf("      Token %d = (%s, %s)\n",i + 1 , lexicalTokens[i].value.c_str(), LexicalType::toString[lexicalTokens[i].type].c_str());
        pushOut(status);
#endif
    }
}
#endif
