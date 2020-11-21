#include <vector>
#include <iostream>
#include <queue>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {

	vector<int> answer;
public:
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> nodeQ;
		if (root == nullptr) {
			return answer;
		}
		nodeQ.push(root);
		while (!nodeQ.empty()) {
			answer.push_back(nodeQ.front()->val);
			queue<TreeNode*> tmpQ;
			while (!nodeQ.empty()) {
				if (nodeQ.front()->right != nullptr) {
					tmpQ.push(nodeQ.front()->right);
				}
				if (nodeQ.front()->left != nullptr) {
					tmpQ.push(nodeQ.front()->left);
				}
				nodeQ.pop();
			}
			nodeQ = tmpQ;
		}
		return answer;
	}
};