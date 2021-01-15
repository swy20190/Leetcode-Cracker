#include <vector>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

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
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> _nums;
		while (head != nullptr) {
			_nums.push_back(head->val);
			head = head->next;
		}
		return sortedArrayToBST(_nums);
	}

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


