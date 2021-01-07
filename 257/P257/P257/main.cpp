#include <vector>
#include <string>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> answer;
		if (root == nullptr) {
			return answer;
		}
		dfs(root, answer, "");
		return answer;
	}

	void dfs(TreeNode *root, vector<string> &answer, string curr) {
		curr = curr + to_string(root->val);

		if (root->left == nullptr && root->right == nullptr) {
			answer.push_back(curr);
			return;
		}
		if (root->left != nullptr) {
			dfs(root->left, answer, curr + "->");
		}
		if (root->right != nullptr) {
			dfs(root->right, answer, curr + "->");
		}
	}
};