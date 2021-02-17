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
private:
	unordered_map<int, int> record;
public:
	TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l, int r, int& pos_Index) {
		if (l == r)
			return NULL;

		
		int index_Val = postorder[pos_Index];
		int index = record.find(index_Val)->second;
		TreeNode* root = new TreeNode(index_Val);   
		pos_Index--;                               
		if (pos_Index >= 0) {
			root->right = build(inorder, postorder, index + 1, r, pos_Index);
			root->left = build(inorder, postorder, l, index, pos_Index);
		}

		return root;

	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0)
			return NULL;
		int n = inorder.size();
		for (int i = 0; i < n; i++)
			record.insert(make_pair(inorder[i], i));  
		int pos_Index = n - 1;

		return build(inorder, postorder, 0, n, pos_Index);
	}
};