#include <vector>
#include <map>
#include <algorithm>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	map<int, vector<pair<int, int>>> S;
	void dfs(TreeNode* root, int u, int v) {
		if (root == NULL) {
			return;
		}
		S[v].push_back({ u, root->val });
		dfs(root->left, u + 1, v - 1);
		dfs(root->right, u + 1, v + 1);
	}
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		dfs(root, 0, 0);
		vector<vector<int>> answer;
		for (auto[x, y] : S) {
			sort(y.begin(), y.end());
			vector<int> v;
			for (auto a : y) {
				v.push_back(a.second);
			}
			answer.push_back(v);
		}
		return answer;
	}
};