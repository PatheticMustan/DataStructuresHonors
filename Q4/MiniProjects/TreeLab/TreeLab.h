class TreeNode {
	private:
		char value;
		TreeNode* left;
		TreeNode* right;

		// shortcut constructor
		TreeNode(char s) {
			value = s; left = NULL; right = NULL;
		}
	
	public:
		// takes a string parameter and builds a BST where each letter is a node
		TreeNode* buildTree(string s) {
			TreeNode* r = new TreeNode('v'); // uhhhh as long as s isn't empty, 'v' should be replaced

			for (int i=0; i<s.length(); i++) {
				if (i==0) 	r->value = s[i];
				else 		insert(r, s[i]);
			}

			return r;
		}

		// inserts a node containing the character into the tree
		void insert(TreeNode* t, char s) {
			TreeNode* target = t;
			
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
				} else {
					// right node
					if (target->right == NULL) {
						target->right = new TreeNode(s);
						break;
					} else {
						target = target->right;
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
						string(1, t->value) :
						display(t->left, level-1) + display(t->right, level-1);
		}

		string preorderTraverse(TreeNode* t) {
			return
				(t==NULL)?
					"" :
					string(1, t->value) + preorderTraverse(t->left) + preorderTraverse(t->right);
		}
		string inorderTraverse(TreeNode* t) {
			return
				(t==NULL)?
					"" :
					inorderTraverse(t->left) + string(1, t->value) + inorderTraverse(t->right);
		}

		string postorderTraverse(TreeNode* t) {
			return
				(t==NULL)?
					"" :
					postorderTraverse(t->left) + postorderTraverse(t->right) + string(1, t->value);
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

		// this is so funny to me
		int countOnlyChildren(TreeNode* t) {
			return
				(t==NULL)?
					0 :
					int(t->left==NULL ^ t->right==NULL) + countOnlyChildren(t->left) + countOnlyChildren(t->right);
		}

		// this is even funnier
		int countGrandParents(TreeNode* t) { 
			return
				(t==NULL)?
					0 :
					int(display(t, 2) != "") + countGrandParents(t->left) + countGrandParents(t->right);
		}

		// returns the max of the heights to the left and the heights to the right
		// should i even bother expanding this, when it's so deliciously concise
		int height(TreeNode* t) {
			return (t==NULL)? 0 : std::max(height(t->left), height(t->right)) + 1;
		}

		// return the max of the sum of the heights to the left and the heights to the right
		int longestPath(TreeNode* t) {
			// return height(t->left) + height(t->right);

			// this handles an edgecase where the longest path does not pass through the root node
			return 
				(t==NULL)?
					0 :
					std::max(
						height(t->left) + height(t->right),
						std::max(longestPath(t->left), longestPath(t->right)));
		}

		// check along left edge
		char min(TreeNode* t) {
			return 
				(t == NULL)?
					127 :
					std::min(
						t->value,
						(t->left!=NULL)? min(t->left) : min(t->right));
		}

		char max(TreeNode* t) {
			return 
				(t == NULL)?
					0 :
					std::max(
						t->value,
						(t->right!=NULL)? max(t->right) : max(t->left));
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
				r.append(displayCurrentLevel(t, i)); // (+ " ") ?????
			}
			return r;
		}
	
	// this class must contain the character representing the current letter as well as
	// pointers to the left and right children
	// you may have TreeNode objects or TreeNode pointers as parameters/returns based
	// upon how you set up your code
};  