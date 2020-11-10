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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> answer;
		queue<TreeNode*> node_q;
		if (root == nullptr) {
			return answer;
		}
		node_q.push(root);
		while (1) {
			queue<TreeNode*> next_q;
			vector<int> current_level;
			while (!node_q.empty()) {
				current_level.push_back(node_q.front()->val);
				if (node_q.front()->left != nullptr) {
					next_q.push(node_q.front()->left);
				}
				if (node_q.front()->right != nullptr) {
					next_q.push(node_q.front()->right);
				}
				node_q.pop();
			}
			answer.push_back(current_level);
			if (next_q.empty()) {
				break;
			}
			node_q = next_q;
		}
		return answer;
	}
};