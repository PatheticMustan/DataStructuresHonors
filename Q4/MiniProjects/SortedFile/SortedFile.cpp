/**
 * Write a program that reads in a text file (input.txt),
 * stores all of the words in a binary search tree,
 * and outputs the word followed by a colon and a space and then
 * the number of times it appears, one per line (result.txt).
 * "He" and "he" are different words. Order them in proper ASCII arrangement.
 * File will contain no punctuation. Standard rules apply.
 * 
 * Please keep all code for your binary search tree in a header file
 * and handle your input and output in your SortedFile.cpp file.
 */

#include <bits/stdc++.h>
using namespace std;

#include "BSTree.h"

int main() {
	TreeNode* root = new TreeNode("");

    ifstream input("input.txt");
    ofstream result("result.txt");
    
	string word = "";
    if (input.is_open() && result.is_open()) {
        while (input >> word) {
            root->insert(root, word);
        }

        // convert result to sorted
        stringstream river; river << root->inorderTraverse(root);
        int count;
        while (river >> word >> count) {
            result << word << " " << count << endl;
        }

        input.close();
        result.close();
    } else {
        cout << "unable to open one of the files...?" << endl;
    }

    

	return 0;
}