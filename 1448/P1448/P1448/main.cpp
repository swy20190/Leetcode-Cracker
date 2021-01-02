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
	int answer;
public:
	int goodNodes(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		checkNode(root, root->val);
		return answer;
	}

	void checkNode(TreeNode* node, int curr_max) {
		if (node == nullptr) {
			return;
		}
		if (curr_max <= node->val) {
			answer++;
		}
		checkNode(node->left, max(curr_max, node->val));
		checkNode(node->right, max(curr_max, node->val));
	}
};