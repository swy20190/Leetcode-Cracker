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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return build(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
	}

	TreeNode* build(int pre_start, int pre_end, int in_start, int in_end, vector<int>& pre, vector<int>& in) {
		if (pre_start > pre_end || in_start > in_end) {
			return nullptr;
		}
		TreeNode* root = new TreeNode(pre[pre_start]);
		int root_in = in_start;
		while (root_in <= in_end && in[root_in] != pre[pre_start]) {
			root_in++;
		}
		int left_bias = root_in - in_start;
		root->left = build(pre_start + 1, pre_start + left_bias, in_start, root_in - 1, pre, in);
		root->right = build(pre_start + left_bias + 1, pre_end, root_in + 1, in_end, pre, in);
		return root;
	}

};