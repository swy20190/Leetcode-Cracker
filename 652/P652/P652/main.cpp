#include <vector>
#include <unordered_map>
#include <string>

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
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		vector<TreeNode*> ans;
		unordered_map<string, int> map;
		serialize(root, ans, map);
		return ans;
	}

	string serialize(TreeNode* root, vector<TreeNode*>& answer, unordered_map<string, int>& map) {
		if (root == nullptr) {
			return "!";
		}
		string curr_tree = to_string(root->val) + "#" + serialize(root->left, answer, map) + "#" + serialize(root->right, answer, map);
		if (map[curr_tree] == 1) {
			answer.push_back(root);
		}
		map[curr_tree]++;
		return curr_tree;
	}
};