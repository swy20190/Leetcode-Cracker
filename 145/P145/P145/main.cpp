#include <vector>
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

	vector<int> answer;
public:
	vector<int> postorderTraversal(TreeNode* root) {
		postTree(root);
		return answer;
	}

	void postTree(TreeNode* root) {
		if (root == nullptr) {
			return;
		}
		postTree(root->left);
		postTree(root->right);
		answer.push_back(root->val);
	}
};