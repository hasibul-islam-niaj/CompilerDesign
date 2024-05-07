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
        for (int i = 0; i < rule.length(); i++){
            if (rule[i] == targetCharacter) {
                ruleToReplace = rule;
                break;
            }
        }
    }
    return ruleToReplace;
}

bool isThereAnyTargetCharacterNext(char targetCharacter, string preparedWord, int index) {
    for (int i = index; i < preparedWord.length() - 1; i++) {
        if (preparedWord[i] == targetCharacter)
            return true;
    }
    return false;
}

bool isThereEpsilonExists(vector<string> workingRules, char targetCharacter) {
    for (string rule: workingRules) {
        if (rule == "E") {
            return true;
        }
    }

    return false;
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

                if ((isThereAnyTargetCharacterNext(targetCharacter,preparedWord,preparingIndex)
                     || isThereAnyTargetCharacterNext(requiredWord[preparingIndex],preparedWord,preparingIndex))
                    && isThereEpsilonExists(workingRules, preparedWord[preparingIndex])){
                    ruleToReplace = "";
                }
                else
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

string rightMostDerivation(string input, string requiredWord, map<char, vector<string>> rules) {
    std::reverse(requiredWord.begin(), requiredWord.end());

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
                if ((isThereAnyTargetCharacterNext(targetCharacter,preparedWord,preparingIndex)
                || isThereAnyTargetCharacterNext(requiredWord[preparingIndex],preparedWord,preparingIndex))
                && isThereEpsilonExists(workingRules, preparedWord[preparingIndex])){
                    ruleToReplace = "";
                }
                else
                    ruleToReplace = findTheRuleToReplace(targetCharacter, workingRules);
            }

            std::reverse(ruleToReplace.begin(), ruleToReplace.end());
            preparedWord.replace(preparingIndex, 1, ruleToReplace);

            string viewWord = preparedWord;
            std::reverse(viewWord.begin(), viewWord.end());
            cout << "Step-" << stepCounter++ << ": " + viewWord << endl;
            if (preparedWord[preparingIndex] == requiredWord[preparingIndex])
                preparingIndex++;
        }

        workingRules.clear();
    }

    std::reverse(preparedWord.begin(), preparedWord.end());
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
    string word = "bc";

    map<char, vector<string>> rules;
    vector<string> data = {};
    rules.insert(make_pair('S', vector<string> {"AAB"}));
    rules.insert(make_pair('A', vector<string> {"bBE", "BB", "A", "E"}));
    rules.insert(make_pair('B', vector<string> {"c", "AB", "E"}));
    rules.insert(make_pair('D', vector<string> {"E"}));

    string input = "S";

    cout << "Left Most Derivation: " << endl;
    string preparedWord = leftMostDerivation(input, word, rules);
    cout << "The word: " << preparedWord << "\n\n" << endl;

    cout << "Right Most Derivation: " << endl;
    preparedWord = rightMostDerivation(input, word, rules);
    cout << "The word: " << preparedWord << endl;

    return 0;
}