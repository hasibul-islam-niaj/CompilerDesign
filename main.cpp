#include <iostream>
#include "Compiler/LexicalAnalysis.h"

char findRuleWhereCharacterExists(char requiredCharacter, map<char, vector<string>> &rules) {
    char setOfRule;

    for (const auto& kv : rules) {
        const auto& characterSets = kv.second;

        for (const auto& characterSet : characterSets) {
            if (characterSet[0] == requiredCharacter) {
                setOfRule = kv.first;
                break;
            }
        }
    }

    return setOfRule;
}

string findTheRuleToReplace(char targetCharacter, vector<string> workingRules) {
    string ruleToReplace;
    for (string rule: workingRules) {
        if (rule[0] == targetCharacter) {
            ruleToReplace = rule;
            break;
        }
    }
    return ruleToReplace;
}

string leftMostDerivation(string input, string requiredWord, map<char, vector<string>> rules) {
    string preparedWord = input;
    int preparingIndex = 0;

    char workingCharacter, targetCharacter;
    vector<string> workingRules;
    string ruleToReplace;
    int stepCounter = 1;
    while (requiredWord != preparedWord) {
        ruleToReplace = "";
        targetCharacter = requiredWord[preparingIndex];
        workingCharacter = preparedWord[preparingIndex];

        if (preparedWord[preparingIndex] != targetCharacter){
            if (!rules[workingCharacter].empty())
                workingRules = rules[workingCharacter];

            ruleToReplace = findTheRuleToReplace(targetCharacter, workingRules);

            if (ruleToReplace == "") {
                targetCharacter = findRuleWhereCharacterExists(requiredWord[preparingIndex], rules);
                ruleToReplace = findTheRuleToReplace(targetCharacter, workingRules);
            }

            preparedWord.replace(preparingIndex, 1, ruleToReplace);

            cout << "Step-" << stepCounter++ << ": " + preparedWord << endl;
            if (preparedWord[preparingIndex] == requiredWord[preparingIndex])
                preparingIndex++;
        }

        workingRules.clear();
    }

    return preparedWord;
}

int main() {
    /***
    // Lexical analysis
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

//    string word = "abc";
    string word = "bccb";

    map<char, vector<string>> rules;
    vector<string> data = {};
    rules.insert(make_pair('S', vector<string> {"AAB", "aAB"}));
    rules.insert(make_pair('A', vector<string> {"b", "BB", "E"}));
    rules.insert(make_pair('B', vector<string> {"c", "AB", "E"}));

    /*
     * AAB
     * bAB
     * bBBB
     * bcBB
     * bccB
     * bccAB
     * bccbB
     * bccb*/

    string input = "S";

    string preparedWord = leftMostDerivation(input, word, rules);
    cout << "The word: " << preparedWord << endl;

    return 0;
}