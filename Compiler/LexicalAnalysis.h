//
// Created by hasibul on 2/11/24.
//

#ifndef COMPILERDESIGN_LEXICALANALYSIS_H
#define COMPILERDESIGN_LEXICALANALYSIS_H

#include "iostream"
#include "string"
#include "regex"
#include "TokenLibrary.h"

using namespace std;

class LexicalAnalysis {
private:
    Token tokens[numberOfToken];

public:
    void generateSourceToken(string code);
    LexicalAnalysis();
};


#endif //COMPILERDESIGN_LEXICALANALYSIS_H
