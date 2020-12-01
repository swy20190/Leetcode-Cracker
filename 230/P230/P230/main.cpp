#include <iostream>
#include <stack>

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
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> sstack;
		int cnt = 0;
		while (!sstack.empty() || root) {
			while (root) {
				sstack.push(root);
				root = root->left;
			}
			root = sstack.top();
			cnt++;
			if (cnt == k) {
				return root->val;
			}
			sstack.pop();
			root = root->right;
		}
		return 0;
	}
};