#include <vector>
#include <queue>

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
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> answer;
		if (root == nullptr) {
			return answer;
		}
		queue<Node*> assist;
		assist.push(root);
		while (!assist.empty()) {
			queue<Node*> tmp;
			vector<int> floor;
			while (!assist.empty()) {
				Node* curr = assist.front();
				assist.pop();
				floor.push_back(curr->val);
				for (Node* child : curr->children) {
					tmp.push(child);
				}
			}
			answer.push_back(floor);
			assist = tmp;
		}
		return answer;
	}
};