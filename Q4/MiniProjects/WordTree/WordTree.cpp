/**
 * Write a program that reads in a text file (input.txt) and stores all of the words using a Trie,
 * as described in the attached document.
 * Output the alphabetized words into result.txt, but display the file information in standard output.
 * File will contain no punctuation and only lower-case letters.
 * The sample file here has one word per line, but your program should work with paragraphs as well.
 * Standard rules apply.
 * 
 * Please keep all code for your trie in a header file and handle your input and output in your WordTree.cpp file.
 * The required methods are listed in the document, but you may include other methods if you choose to do so.
 */

#include <bits/stdc++.h>
using namespace std;

#include "BSTree.h"

int main() {
	WordNode* root;

    ifstream input("input.txt");
    ofstream result("result.txt");
    
	int count = 0;
    if (input.is_open() && result.is_open()) {
        root->buildTree(input, count);

        cout << endl << count << endl;
        
        input.close();
        result.close();
    } else {
        cout << "unable to open one of the files...?" << endl;
    }

    

	return 0;
}