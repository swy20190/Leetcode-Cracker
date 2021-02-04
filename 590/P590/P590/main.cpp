#include <vector>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};


class Solution {
public:
	vector<int> postorder(Node* root) {
		vector<int> answer;
		back(root, answer);
		return answer;
	}

	void back(Node* root, vector<int>& ans) {
		if (root == nullptr) {
			return;
		}
		for (auto n : root->children) {
			back(n, ans);
		}
		ans.push_back(root->val);
	}
};