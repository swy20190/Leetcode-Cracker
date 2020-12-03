#include <vector>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	vector<TreeNode*> allPossibleFBT(int N) {
		vector<TreeNode*> answer;
		if (N == 1) {
			answer.push_back(new TreeNode(0));
			return answer;
		}
		for (int i = 1; i <= N - 2; i++) {
			vector<TreeNode*> left = allPossibleFBT(i);
			vector<TreeNode*> right = allPossibleFBT(N - 1 - i);
			for (TreeNode* l : left) {
				for (TreeNode* r : right) {
					TreeNode* tmp = new TreeNode(0);
					tmp->left = l;
					tmp->right = r;
					answer.push_back(tmp);
				}
			}
		}
		return answer;
	}
};