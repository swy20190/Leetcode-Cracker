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
	int maxDepth(Node* root) {
		if (root == nullptr) {
			return 0;
		}
		if (root->children.empty()) {
			return 1;
		}
		int tmp_max = 0;
		for (auto child : root->children) {
			int d = maxDepth(child);
			if (d > tmp_max) {
				tmp_max = d;
			}
		}
		return 1 + tmp_max;
	}
};