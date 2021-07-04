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
	int answer = 0;
	int dfs(TreeNode* node) {
		if (node == NULL) {
			return 0;
		}
		int l = dfs(node->left);
		int r = dfs(node->right);
		answer += abs(l) + abs(r);
		return node->val + l + r - 1;
	}
public:
	int distributeCoins(TreeNode* root) {
		answer = 0;
		dfs(root);
		return answer;
	}
};