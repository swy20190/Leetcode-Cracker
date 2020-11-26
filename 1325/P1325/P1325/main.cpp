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
	TreeNode* removeLeafNodes(TreeNode* root, int target) {
		if (root == nullptr) {
			return nullptr;
		}
		TreeNode* l = removeLeafNodes(root->left, target);
		TreeNode* r = removeLeafNodes(root->right, target);
		if (l == nullptr && r == nullptr && root->val == target) {
			root = nullptr;
			return nullptr;
		}
		else {
			root->left = l;
			root->right = r;
			return root;
		}
	}
};