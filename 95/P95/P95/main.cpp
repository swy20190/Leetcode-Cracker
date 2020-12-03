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
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) {
			vector<TreeNode*> answer;
			return answer;
		}
		return dp(1, n);
	}

	vector<TreeNode*> dp(int start, int end) {
		vector<TreeNode*> ret;
		if (start == end) {
			TreeNode* root = new TreeNode(start);
			ret.push_back(root);
			return ret;
		}
		for (int i = start + 1; i <= end - 1; i++) {
			vector<TreeNode*> left = dp(start, i - 1);
			vector<TreeNode*> right = dp(i + 1, end);
			for (TreeNode* l_root : left) {
				for (TreeNode* r_root : right) {
					TreeNode* root = new TreeNode(i, l_root, r_root);
					ret.push_back(root);
				}
			}
		}
		vector<TreeNode*> all_left = dp(start, end - 1);
		vector<TreeNode*> all_right = dp(start + 1, end);
		for (TreeNode* l : all_left) {
			TreeNode* root = new TreeNode(end, l, nullptr);
			ret.push_back(root);
		}
		for (TreeNode* r : all_right) {
			TreeNode* root = new TreeNode(start, nullptr, r);
			ret.push_back(root);
		}
		return ret;
	}
};