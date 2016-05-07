
#include "Recognizer.h"

vector<string> ReadSequence(string fileName)
{
    vector<string> sequences;
    ifstream file(fileName);
    string str;
    while (getline(file, str))
        sequences.push_back(str);
    file.close();
    return sequences;
}

void clear()
{
    freopen("input.txt", "w", stdout);
    cout << "const real a = 2;" << endl;
    fclose(stdout);
}

int main()
{
    //TODO: Make division on DEBUG AND REALESE
    //TODO: Refact enums and so on

    //clear();
    freopen("output.txt", "w", stdout);
    Recognizer recognizer;
    vector<string> source = ReadSequence("input.txt");
    for (vector<string>::iterator i = source.begin(); i != source.end(); ++i)
        if (recognizer.Check(*i))
            printf("Accepted\n");
        else
            printf("Rejected\n");
}