#include <vector>
#include <iostream>
#include <stack>

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
	vector<int> preorder(Node* root) {
		stack<Node*> tmp;
		vector<int> answer;
		if (root == nullptr) {
			return answer;
		}
		tmp.push(root);
		while (!tmp.empty()) {
			Node* curr = tmp.top();
			tmp.pop();
			answer.push_back(curr->val);
			int len = curr->children.size();
			for (int i = len - 1; i >= 0; i--) {
				tmp.push(curr->children[i]);
			}
		}
		return answer;
	}
};