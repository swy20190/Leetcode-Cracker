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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.size() == 0) {
			return nullptr;
		}
		return build(nums, 0, nums.size() - 1);
	}

	TreeNode* build(vector<int>& nums, int low, int high) {
		if (low == high) {
			return new TreeNode(nums[high]);
		}
		int maxIndex = low;
		for (int i = low; i <= high; i++) {
			if (nums[i] > nums[maxIndex]) {
				maxIndex = i;
			}
		}
		TreeNode* ret = new TreeNode(nums[maxIndex]);
		if (maxIndex == low) {
			ret->left = nullptr;
		}
		else {
			ret->left = build(nums, low, maxIndex - 1);
		}
		if (maxIndex == high) {
			ret->right = nullptr;
		}
		else {
			ret->right = build(nums, maxIndex + 1, high);
		}
		return ret;
	}
};