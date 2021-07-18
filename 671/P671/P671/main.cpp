#include <iostream>
#include <algorithm>

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
	int traverse(TreeNode* root, int value) {
		if (root == NULL) {
			return -1;
		}
		if (root->val > value) {
			return root->val;
		}
		int l = traverse(root->left, value);
		int r = traverse(root->right, value);
		if (l >= 0 && r >= 0) {
			return min(l, r);
		}
		return max(l, r);
	}
public:
	int findSecondMinimumValue(TreeNode* root) {
		return traverse(root, root->val);
	}
};