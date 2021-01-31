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
	vector<double> averageOfLevels(TreeNode* root) {
		auto avgs = vector<double>();
		auto q = queue<TreeNode*>();
		q.push(root);
		while (!q.empty()) {
			double sum = 0;
			int size = q.size();
			for (int i = 0; i < size; i++) {
				auto node = q.front();
				q.pop();
				sum += node->val;
				auto left = node->left;
				auto right = node->right;
				if (left != nullptr) {
					q.push(left);
				}
				if (right != nullptr) {
					q.push(right);
				}
			}
			avgs.push_back(sum / size);
		}
		return avgs;
	}
};