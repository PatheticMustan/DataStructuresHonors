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
			for (int i=0; i<26; i++) children[i] = NULL;
			endOfWord = false;
		}

		WordNode* buildTree(ifstream &input, int &count) {
			string word = "";
			while (input >> word) {
				count += word.length();
				insert(this, word);
			}
			return this;
		}

		void insert(WordNode* root, string word) {
			// originally pointing to root
			WordNode* t = root;
			for (int i=0; i<word.length(); i++) {
				if (t->children[word[i]-'a'] == NULL) {
					// the character doesn't exist, create a new one
					t->children[word[i]-'a'] = new WordNode();
				}
				t = t->children[word[i]-'a'];
			}
			t->endOfWord = true;
		}

		void traverse(string prefix, WordNode* w, ofstream &file);
		int countNodes(WordNode* w) {
			int c = 1;
			for (int i=0; i<26; i++) {
				c += w->children[i]==NULL? 0 : countNodes(w->children[i]);
			}
			return c;
		}
};

#endif