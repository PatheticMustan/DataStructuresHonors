#include <bits/stdc++.h>
using namespace std;

#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
	private:
		string value;
		int count;
		TreeNode* left;
		TreeNode* right;
	
	public:
		TreeNode(string s) {
			value = s; count = 1; left = NULL; right = NULL;
		}

		void insert(TreeNode* t, string s) {
			TreeNode* target = t;
			
			// there are no values in the tree, init root node
			if (t->value == "") {
				t->value = s;
				t->count = 1;
			} else {
				// mwahahhahah while true
				while (true) {
					if (target->value > s) {
						// left node
						if (target->left == NULL) {
							target->left = new TreeNode(s);
							break;
						} else {
							target = target->left;
						}
					} else if (target->value < s)  {
						// right node
						if (target->right == NULL) {
							target->right = new TreeNode(s);
							break;
						} else {
							target = target->right;
						}
					} else {
						// word already exists, increase count by one
						target->count++;
						break;
					}
				}
			}
		}

		// this is where the fun begins
		// formatted for optimal eyebleeding
		string display(TreeNode* t, int level) {
			return
				(t==NULL)?
					"" :
					(level==0)?
						(t->value + ":" + to_string(t->count)) + " " :
						display(t->left, level-1) + display(t->right, level-1);
		}

		int countNodes(TreeNode* t) {
			return
				(t==NULL)?
					0 :
					1 + countNodes(t->left) + countNodes(t->right);
		}
		int countLeaves(TreeNode* t) {
			return
				(t==NULL)?
					0 :
					(t->left==NULL && t->right==NULL)?
						1 :
						countLeaves(t->left) + countLeaves(t->right);
		}

		// returns the max of the heights to the left and the heights to the right
		// should i even bother expanding this, when it's so deliciously concise
		int height(TreeNode* t) {
			return (t==NULL)? 0 : std::max(height(t->left), height(t->right)) + 1;
		}

		// check along left edge
		string min(TreeNode* t) {
			if (t == NULL) return "";

			string a = t->value;
			string b = (t->left!=NULL)? min(t->left) : min(t->right);

			// manually remove empty strings
			if (a == "") return b;
			if (b == "") return a;

			// compare the two, return the lower
			return (a.compare(b)<0)? a : b;
		}
		
		// same as min, but check the right edge
		string max(TreeNode* t) {
			if (t == NULL) return "";

			string a = t->value;
			string b = (t->right!=NULL)? max(t->right) : max(t->left);

			// manually remove empty strings
			if (a == "") return b;
			if (b == "") return a;

			// compare the two, return the lower
			return (a.compare(b)>0)? a : b;
		}

		// apparently this is just a weird way to display
		string displayCurrentLevel(TreeNode* t, int level) {
			return display(t, level);
		}

		// display tree by level
		// i don't want to figure out how to make this recursive, so i guess this'll just have to be written normally
		string displayLevelOrder(TreeNode* t) {
			int h = height(t);
			string r = "";
			for (int i=0; i<h; i++) {
				r.append(displayCurrentLevel(t, i));
				if (i != h-1) r.append("\n");
			}
			return r;
		}
};

#endif