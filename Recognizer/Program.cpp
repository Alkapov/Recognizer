
#include "Recognizer.h"
#include "stdafx.h"

vector<string> ReadSequence(string fileName)
{
    vector<string> sequences;
    std::ifstream file("Read.txt");
    std::string str;
    while (std::getline(file, str))
        sequences.push_back(str);
    file.close();
    return sequences;
}

int main()
{
    freopen("output.txt", "w", stdout);
    Recognizer recognizer;
    vector<string> source = ReadSequence("input.txt");
    for (vector<string>::iterator i = source.begin(); i != source.end(); ++i)
        if (recognizer.Check(*i))
            printf("Accepted\n");
        else
            printf("Rejected\n");
}