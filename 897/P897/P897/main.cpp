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
	TreeNode* solve(TreeNode* root, TreeNode* tail) {
		if (!root) {
			return NULL;
		}
		auto right = solve(root->right, tail);
		if (!right) {
			right = tail;
		}
		auto left = solve(root->left, root);
		if (!left) {
			left = root;
		}
		root->right = right;
		root->left = NULL;
		return left;
	}
public:
	TreeNode* increasingBST(TreeNode* root) {
		return solve(root, NULL);
	}
};