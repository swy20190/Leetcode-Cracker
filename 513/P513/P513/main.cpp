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
	int max_depth = INT_MIN;
	int answer;
public:
	int findBottomLeftValue(TreeNode* root) {
		dfs(root, 0);
		return answer;
	}

	void dfs(TreeNode* node, int curr_depth) {
		if (node == nullptr) {
			return;
		}
		if (node->left == nullptr && node->right == nullptr) {
			if (curr_depth > max_depth) {
				max_depth = curr_depth;
				answer = node->val;
			}
		}
		dfs(node->left, curr_depth + 1);
		dfs(node->right, curr_depth + 1);
	}
};