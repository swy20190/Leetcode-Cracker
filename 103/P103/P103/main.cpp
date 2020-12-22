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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> answer;
		queue<TreeNode*> q;
		if (root != nullptr) {
			q.push(root);
		}
		bool left = true;
		while (!q.empty()) {
			int len = q.size();
			vector<int> curr_row(len, 0);
			len--;
			while (len > 0) {
				len--;
				root = q.front();
				q.pop();
				curr_row[left ? curr_row.size() - len - 1 : len] = root->val;
				if (root->left != nullptr) {
					q.push(root->left);
				}
				if (root->right != nullptr) {
					q.push(root->right);
				}
			}
			answer.push_back(curr_row);
			left = !left;
		}
		return answer;
	}
};