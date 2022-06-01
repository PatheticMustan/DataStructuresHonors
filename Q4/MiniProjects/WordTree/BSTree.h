#include <bits/stdc++.h>
using namespace std;

#ifndef WORDNODE_H
#define WORDNODE_H

class WordNode {
	private:
		WordNode* children[26];
		bool endOfWord;
	
	public:
		WordNode() {
			for (int i=0; i<26; i++) cout << children[i] << endl;
			endOfWord = false;
		}
		WordNode* buildTree(ifstream &input, int &count) {
			string word = "";
			while (input >> word) {
				count += word.length();
				cout << word << " " << endl;


				WordNode* t = this;
				for (int i=0; i<word.length(); i++) {
					cout << "natsumi" << " " << t->children[word[i]-'a'] << endl;
					if (t->children[word[i]-'a'] == NULL) {
						// the character doesn't exist, create a new one
						t->children[word[i]-'a'] = new WordNode();
					}

					t = t->children[word[i]-'a'];
				}
				t->endOfWord = true;
			}
			return this;
		}
		void insert(WordNode* w, string s);
		void traverse(string prefix, WordNode* w, ofstream &file);
		int countNodes(WordNode* w);

		
};

#endif