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
	int sumNumbers(TreeNode* root) {
		return sumWithDigit(root, 0);
	}

	int sumWithDigit(TreeNode* root, int tmp_sum) {
		if (root == nullptr) {
			return 0;
		}
		else if (root->left == nullptr && root->right == nullptr) {
			return 10 * tmp_sum + root->val;
		}
		return sumWithDigit(root->left, 10 * tmp_sum + root->val) + sumWithDigit(root->right, 10 * tmp_sum + root->val);
	}
};