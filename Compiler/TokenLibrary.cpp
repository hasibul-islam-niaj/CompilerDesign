//
// Created by hasibul on 2/12/24.
//

#include "TokenLibrary.h"
using namespace std;

string DATA_TYPES_PATTERN = "\\b(int|char|float|string)\\b";
string KEYWORDS_PATTERN = DATA_TYPES_PATTERN
                          + "|\\b(if|else(?!\\s+if)|else\\s+if"
                            "|while|Do|for"
                            "|switch|case"
                            "|break|continue|return)\\b";
string PUNCTUATION_PATTERN = ":|;|,";
string IDENTIFIER_PATTERN = "\\b(?!(" + KEYWORDS_PATTERN + "|" + PUNCTUATION_PATTERN + ")\\b)([a-zA-Z][_a-zA-Z$0-9]*)";
string CONSTANTS_PATTERN = "\\b\\d+(\\.\\d+)?\\b";
string PARENTHESIS_PATTERN = "\\(|\\)|\\{|\\}|\\[|\\]";
string LOGICAL_OPERATOR_PATTERN = "==|!=|<(?!=)|<=|>(?!=)|>=|&&|\\|\\||!(?!=)";
string ARITHMETIC_OPERATOR_PATTERN = "\\+|\\-|\\*|\\/|\\%|[^(=!<>)]\\=[^(=]";

TokenLibrary::TokenLibrary() {
    tokens[0] = {"Data-Type", DATA_TYPES_PATTERN};
    tokens[1] = {"Keyword", KEYWORDS_PATTERN};
    tokens[2] = {"Identifier", IDENTIFIER_PATTERN};
    tokens[3] = {"Constants", CONSTANTS_PATTERN};
    tokens[4] = {"Parenthesis", PARENTHESIS_PATTERN};
    tokens[5] = {"Punctuation", PUNCTUATION_PATTERN};
    tokens[6] = {"Arithmetic-Operator", ARITHMETIC_OPERATOR_PATTERN};
    tokens[7] = {"Logical-Operator", LOGICAL_OPERATOR_PATTERN};
}

Token *TokenLibrary::getTokens() {
    return tokens;
}
