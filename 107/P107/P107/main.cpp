#include <vector>
#include <queue>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		queue<TreeNode*> curr_layer;
		curr_layer.push(root);
		vector<vector<int>> answer;
		if (root == nullptr) {
			return answer;
		}
		while (!curr_layer.empty()) {
			vector<int> layer_value;
			queue<TreeNode*> next_layer;
			while (!curr_layer.empty()) {
				TreeNode* curr_node = curr_layer.front();
				curr_layer.pop();
				layer_value.push_back(curr_node->val);
				if (curr_node->left != nullptr) {
					next_layer.push(curr_node->left);
				}
				if (curr_node->right != nullptr) {
					next_layer.push(curr_node->right);
				}
			}
			curr_layer = next_layer;
			answer.push_back(layer_value);
		}
		reverse(answer.begin(), answer.end());
		return answer;
	}
};