#include <iostream>
#include <algorithm>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
	int depth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		return max(depth(root->left), depth(root->right))+1;
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		return max(max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)), depth(root->left) + depth(root->right));
	}
};