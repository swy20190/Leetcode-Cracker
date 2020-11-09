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
	void flatten(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		flatten(root->right);
		flatten(root->left);
		TreeNode* current = root->left;
		if (current != nullptr) {
			while (current->right != nullptr) {
				current = current->right;
			}
			current->right = root->right;
			root->right = root->left;
			root->left = nullptr;
		}
	}
};
