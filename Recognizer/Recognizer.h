#pragma once
#include <string>
using namespace std;
class Recognizer
{
    string Read(string fileName);
public:
    Recognizer();
    void Run();
    ~Recognizer();
};

