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
	int answer = INT_MAX;
	TreeNode* prev = NULL;
	void mid(TreeNode* root) {
		if (root == NULL) {
			return;
		}
		mid(root->left);
		if (prev != NULL) {
			answer = min(answer, root->val - prev->val);
		}
		prev = root;
		mid(root->right);
	}
public:
	int getMinimumDifference(TreeNode* root) {
		mid(root);
		return answer;
	}
};