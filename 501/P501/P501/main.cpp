#include <vector>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	vector<int> findMode(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) {
			return res;
		}
		TreeNode* pre = nullptr;
		int curTimes = 1;
		int maxTimes = 0;
		inorder(root, pre, curTimes, maxTimes, res);
		return res;
	}

	void inorder(TreeNode* root, TreeNode*& pre, int& curTimes, int& maxTimes, vector<int>& res) {
		if (!root) {
			return;
		}
		inorder(root->left, pre, curTimes, maxTimes, res);
		if (pre != nullptr) {
			curTimes = (root->val == pre->val) ? curTimes + 1 : 1;
		}
		if (curTimes == maxTimes) {
			res.push_back(root->val);
		}
		else if (curTimes > maxTimes) {
			res.clear();
			res.push_back(root->val);
			maxTimes = curTimes;
		}
		pre = root;
		inorder(root->right, pre, curTimes, maxTimes, res);
	}
};