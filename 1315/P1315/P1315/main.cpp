#include <iostream>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {

	int answer = 0;
public:
	int sumEvenGrandparent(TreeNode* root) {
		traverse(root);
		return answer;
	}

	void traverse(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		if (root->val % 2 == 0) {
			if (root->left) {
				if (root->left->left) {
					answer += root->left->left->val;
				}
				if (root->left->right) {
					answer += root->left->right->val;
				}
			}
			if (root->right) {
				if (root->right->left) {
					answer += root->right->left->val;
				}
				if (root->right->right) {
					answer += root->right->right->val;
				}
			}
		}
		traverse(root->left);
		traverse(root->right);
	}
};