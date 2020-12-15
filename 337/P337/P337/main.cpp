#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
	map<TreeNode*, int> mmap;
public:
	int rob(TreeNode* root) {
		return startRob(root);
	}

	int startRob(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		if (mmap.find(root) != mmap.end()) {
			return mmap[root];
		}
		if (root->left == nullptr && root->right == nullptr) {
			return root->val;
		}
		int sum_1 = startRob(root->left) + startRob(root->right);
		int sum_2 = root->val;
		if (root->right != nullptr) {
			sum_2 += startRob(root->right->right);
			sum_2 += startRob(root->right->left);
		}
		if (root->left != nullptr) {
			sum_2 += startRob(root->left->right);
			sum_2 += startRob(root->left->left);
		}
		int ret = max(sum_1, sum_2);
		mmap[root] = ret;
		return ret;
	}
};