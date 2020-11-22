#include <iostream>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		TreeNode* leftmost = root->left;
		if (root->left != nullptr) {
			while (leftmost->right != nullptr) {
				leftmost = leftmost->right;
			}
			if (leftmost->val >= root->val) {
				return false;
			}
		}
		
		TreeNode* rightmost = root->right;
		if (root->right != nullptr) {
			while (rightmost->left != nullptr) {
				rightmost = rightmost->left;
			}
			if (rightmost->val <= root->val) {
				return false;
			}
		}
		
		bool leftvalid = isValidBST(root->left);
		if (!leftvalid) {
			return false;
		}
		return isValidBST(root->right);
	}
};