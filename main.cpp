#include <iostream>
#include "Compiler/LexicalAnalysis.h"

string leftMostDerivation(string input, string requiredWord, map<char, vector<string>> rules) {
    string preparedWord = input;
    int preparingIndex = 0;

    char workingCharacter;
    vector<string> workingRules;
    while (requiredWord.length() != preparingIndex) {
        workingCharacter = preparedWord[preparingIndex];

        if (preparedWord[preparingIndex] != requiredWord[preparingIndex]){
            if (!rules[workingCharacter].empty())
                workingRules = rules[workingCharacter];

            preparedWord.replace(preparingIndex, workingRules[0].length(), workingRules[0]);

            cout << "Step-" << preparingIndex + 1 << ": " + preparedWord << endl;
            if (preparedWord[preparingIndex] == requiredWord[preparingIndex])
                preparingIndex++;
        }

        workingRules.clear();
    }

    return preparedWord;
}

int main() {
    /***
    LexicalAnalysis lexicalAnalysis;

    string codeLines[5];
    codeLines[0] = "int a = b*c + 10;";
    codeLines[1] = "string data = a == b?passed:failed; float k = 2.434;";
    codeLines[2] = "string *data = &TEST;";
    codeLines[3] = "int 1a = 20;";
    codeLines[4] = "if (a > b) return 500.50;";

    int iterator = 1;
    for(string codeLine: codeLines) {
        cout << "\n\n ~ " << iterator++ << ". " << codeLine << endl;
        lexicalAnalysis.generateSourceToken(codeLine);
    }
     */

    string word = "abc";

    map<char, vector<string>> rules;
    vector<string> data = {};
    rules.insert(make_pair('S', vector<string> {"aAB"}));
    rules.insert(make_pair('A', vector<string> {"b", "E"}));
    rules.insert(make_pair('B', vector<string> {"c", "E"}));

    string input = "S";

    string preparedWord = leftMostDerivation(input, word, rules);
    cout << "The word: " << preparedWord << endl;

    return 0;
}