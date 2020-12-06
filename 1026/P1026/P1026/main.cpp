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
	int max_diff = INT_MIN;
public:
	int maxAncestorDiff(TreeNode* root) {
		reverse(root, root->val, root->val);
		return max_diff;
	}

	void reverse(TreeNode* root, int maxAnces, int minAnces) {
		if (root == nullptr) {
			return;
		}
		if (abs(root->val - maxAnces) > max_diff) {
			max_diff = abs(root->val - maxAnces);
		}
		if (abs(root->val - minAnces) > max_diff) {
			max_diff = abs(root->val - minAnces);
		}
		if (root->val > maxAnces) {
			maxAnces = root->val;
		}
		if (root->val < minAnces) {
			minAnces = root->val;
		}
		reverse(root->left, maxAnces, minAnces);
		reverse(root->right, maxAnces, minAnces);
	}
};