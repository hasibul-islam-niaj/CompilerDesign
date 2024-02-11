//
// Created by hasibul on 2/11/24.
//

#include "LexicalAnalysis.h"

string DATA_TYPES_PATTERN = "int|char|float";
string KEYWORDS_PATTERN = DATA_TYPES_PATTERN
        + "|if|else(?!\\s+if)|else\\s+if"
          "|while|Do|for"
          "|switch|case"
          "|break|continue|return";
string IDENTIFIER_PATTERN = "(\\b(?!(int|char|float)))([&]?[a-zA-Z][a-zA-Z_$\\d]*)";
//string IDENTIFIER_PATTERN = "([a-zA-Z\\&][a-zA-Z_$\\d]*)";
string CONSTANTS_PATTERN = "\\b\\d+\\b";
string PARENTHESIS_PATTERN = "\\(|\\)|\\{|\\}|\\[|\\";
string PUNCTUATION_PATTERN = "[:|;|,]";
string ARITHMETIC_OPERATOR_PATTERN = "\\+|\\-|\\*|\\/|\\%]";
string LOGICAL_OPERATOR_PATTERN = "==|!=|<(?!=)|<=|>(?!=)|>=|&&|\\|\\||!(?!=)";


void LexicalAnalysis::getTokens(std::string codeLine) {
    regex pattern(ARITHMETIC_OPERATOR_PATTERN);

    sregex_iterator iterator(codeLine.begin(), codeLine.end(), pattern);
    sregex_iterator end;

    int i = 1;
    while(iterator != end) {
        smatch matched = *iterator;
        cout << i++ << " " << matched.str() << endl;
        iterator++;
    }
}
