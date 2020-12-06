#include <vector>
#include <unordered_map>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
	unordered_map<int, int> sum_map;
public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		reverse(root);
		vector<int> answer;
		if (root == nullptr) {
			return answer;
		}
		int max = INT_MIN;
		for (auto &p : sum_map) {
			if (p.second > max) {
				max = p.second;
			}
		}
		for (auto &p : sum_map) {
			if (p.second == max) {
				answer.push_back(p.first);
			}
		}
		return answer;
	}

	int reverse(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int sum = root->val + reverse(root->left) + reverse(root->right);
		sum_map[sum] ++;
		return sum;
	}
};