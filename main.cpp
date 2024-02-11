#include <iostream>
#include "Compiler/LexicalAnalysis.h"

int main() {
    LexicalAnalysis lexicalAnalysis;

    string codeLines[4];
    codeLines[0] = "int a = b*c + 10;";
    codeLines[1] = "string data = a == b?passed:failed; float k = 2.434;";
    codeLines[2] = "string *data = &TEST;";
    codeLines[3] = "int 1a = 20;";

    int iterator = 1;
    for(string codeLine: codeLines) {
        cout << "\n\n ~ " << iterator++ << ". " << codeLine << endl;
        lexicalAnalysis.generateSourceToken(codeLine);
    }

    return 0;
}
