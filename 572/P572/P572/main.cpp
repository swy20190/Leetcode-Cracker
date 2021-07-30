#include <iostream>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (root == NULL && subRoot == NULL) {
			return true;
		}
		if (root == NULL && subRoot != NULL) {
			return false;
		}
		return isSametree(root, subRoot)
			|| isSubtree(root->left, subRoot)
			|| isSubtree(root->right, subRoot);
	}

	bool isSametree(TreeNode* s, TreeNode* t) {
		if (s == NULL && t == NULL) {
			return true;
		}
		return s && t&&s->val == t->val
			&& isSametree(s->left, t->left)
			&& isSametree(s->right, t->right);
	}
};