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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return build(nums, 0, nums.size() - 1);
	}

	TreeNode* build(vector<int>& nums, int start, int end) {
		if (start > end) {
			return nullptr;
		}
		if (start == end) {
			return new TreeNode(nums[start]);
		}
		int mid = start + (end - start) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = build(nums, start, mid - 1);
		root->right = build(nums, mid + 1, end);
		return root;
	}
};