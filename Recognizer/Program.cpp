
#include "Test.h"



int main()
{
#if _DEBUG
    Test::Run();
#else
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    Recognizer recognizer;
    string input;
    getline(cin, input);
    if(recognizer.Check(input))
        printf("Accepted\n");
    else
        printf("Rejected\n");
    fclose(stdout);
    fclose(stdin);
#endif
   
}