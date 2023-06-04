// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Tree;
    std::ifstream file(filename);
    std::string word;
    while (!file.eof()) {
        char ch = tolower(file.get());
        if (isalpha(ch)) {
            word += ch;
        }
        else {
            Tree.addword(word);
            word.clear();
        }
    }
    file.close();
    return Tree;
}
