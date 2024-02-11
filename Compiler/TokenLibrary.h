//
// Created by hasibul on 2/12/24.
//

#ifndef COMPILERDESIGN_TOKENLIBRARY_H
#define COMPILERDESIGN_TOKENLIBRARY_H

#include "string"
using namespace std;

const int numberOfToken = 9;
struct Token {
    string name;
    string pattern;
};

class TokenLibrary {
private:
    Token tokens[numberOfToken];

public:
    int getNumberOfTokens() {
        return numberOfToken;
    }
    Token* getTokens();
    TokenLibrary();
};


#endif //COMPILERDESIGN_TOKENLIBRARY_H
