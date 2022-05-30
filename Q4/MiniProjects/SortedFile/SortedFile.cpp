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

	root->insert(root, "banana");
    root->insert(root, "apple");
    root->insert(root, "baNaNa");
    root->insert(root, "car");
    root->insert(root, "cat");
    root->insert(root, "aaaa");
    root->insert(root, "zzz");
    root->insert(root, "applejack");
    root->insert(root, "amongus");
    root->insert(root, "banana");
    root->insert(root, "ZXY");
    root->insert(root, "cookie");
    root->insert(root, "banana");
    root->insert(root, "aaa");
    root->insert(root, "a");
    cout << root->displayLevelOrder(root) << endl;
    cout << root->min(root) << endl;
    cout << root->max(root) << endl;

    ifstream input("input.txt");
    ofstream result("result.txt");
    
	string word = "";
    if (input.is_open() && result.is_open()) {
        while (input >> word) {
			result << word << " . ";
        }
        input.close();
        result.close();
    } else {
        cout << "unable to open one of the files...?" << endl;
    }

    

	return 0;
}