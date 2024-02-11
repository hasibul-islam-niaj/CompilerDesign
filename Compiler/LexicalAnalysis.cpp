//
// Created by hasibul on 2/11/24.
//

#include "LexicalAnalysis.h"
#include "TokenLibrary.h"

void LexicalAnalysis::generateSourceToken(std::string code) {
    for (Token token : tokens) {
        if (token.pattern.empty())
            continue;

        regex pattern(token.pattern);

        sregex_iterator iterator(code.begin(), code.end(), pattern);
        sregex_iterator end;

        int totalToken = 0;
        string wordsInToken = "";
        while(iterator != end) {
            smatch matched = *iterator;

            if (totalToken > 0)
                wordsInToken += ", ";
            wordsInToken += matched.str();

            totalToken += 1;
            iterator++;
        }

        if (totalToken != 0)
           cout << token.name << " (" << totalToken << "): " << wordsInToken << endl;
    }
}

LexicalAnalysis::LexicalAnalysis() {
    TokenLibrary tokenLibrary;
    Token* sourceTokens = tokenLibrary.getTokens();
    for (int i = 0; i < tokenLibrary.getNumberOfTokens(); ++i) {
        tokens[i] = sourceTokens[i];
    }
}
