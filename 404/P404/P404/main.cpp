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
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int answer = 0;
		if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
			answer += root->left->val;
		}
		return answer + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
};