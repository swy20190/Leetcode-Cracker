#include <vector>
#include <queue>

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
	vector<int> largestValues(TreeNode* root) {
		vector<int> answer;
		queue<TreeNode*> curr_row;
		if (root == nullptr) {
			return answer;
		}
		curr_row.push(root);
		while (!curr_row.empty()) {
			queue<TreeNode*> tmp;
			int row_max = INT_MIN;
			while (!curr_row.empty()) {
				if (curr_row.front()->val > row_max) {
					row_max = curr_row.front()->val;
				}
				TreeNode* father = curr_row.front();
				if (father->left != nullptr) {
					tmp.push(father->left);
				}
				if (father->right != nullptr) {
					tmp.push(father->right);
				}
				curr_row.pop();
			}
			answer.push_back(row_max);
			curr_row = tmp;
		}
		return answer;
	}
};