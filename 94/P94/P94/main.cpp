#include <vector>
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

	vector<int> ans;
public:
	vector<int> inorderTraversal(TreeNode* root) {
		traverse(root);
		return ans;
	}

	void traverse(TreeNode* curr) {
		if (curr == nullptr) {
			return;
		}
		else {
			traverse(curr->left);
			ans.push_back(curr->val);
			traverse(curr->right);
		}
	}
};