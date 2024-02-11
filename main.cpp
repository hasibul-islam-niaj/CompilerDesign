#include <iostream>
#include "Compiler/LexicalAnalysis.h"

int main() {
    LexicalAnalysis lexicalAnalysis;
    int a_$1s;
    int *p = &a_$1s;
    std::string codeLine = "int a:, a_b, a_$1s aas_df_$1s, a_$1, ; a_, a_1, a_1828, 1a, for (i=0; i<10; i+=1) {if i<10 {return i-29} else if a > 30 else 6*59}  a_a/5   [&a]";
//    std::string codeLine = "&aasdf asdf";
    lexicalAnalysis.getTokens(codeLine);
    return 0;
}
