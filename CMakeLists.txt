cmake_minimum_required(VERSION 3.24)
project(CompilerDesign)

set(CMAKE_CXX_STANDARD 11)

add_executable(CompilerDesign main.cpp Compiler/LexicalAnalysis.cpp Compiler/LexicalAnalysis.h Compiler/TokenLibrary.cpp Compiler/TokenLibrary.h)
