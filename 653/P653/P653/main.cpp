#include <iostream>
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
	void reverse(TreeNode* root, vector<int>& vec) {
		if (root == NULL) {
			return;
		}
		reverse(root->left, vec);
		vec.push_back(root->val);
		reverse(root->right, vec);
	}
public:
	bool findTarget(TreeNode* root, int k) {
		vector<int> arr;
		reverse(root, arr);
		int begin = 0;
		int end = arr.size() - 1;
		while (begin < end) {
			if (k == arr[begin] + arr[end]) {
				return true;
			}
			else if (k > arr[begin] + arr[end]) {
				begin++;
			}
			else {
				end--;
			}
		}
		return false;
	}
};