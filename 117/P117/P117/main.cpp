#include <iostream>

using namespace std;


class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
	Node* connect(Node* root) {
		if (root == nullptr) {
			return nullptr;
		}
		Node* next = root->next;
		while (next != nullptr) {
			if (next->left != nullptr) {
				next = next->left;
				break;
			}
			else if (next->right != nullptr) {
				next = next->right;
				break;
			}
			else {
				next = next->next;
			}
		}
		if (root->left != nullptr && root->right != nullptr) {
			root->left->next = root->right;
			root->right->next = next;
		}
		else if (root->left == nullptr && root->right != nullptr) {
			root->right->next = next;
		}
		else if (root->left != nullptr && root->right == nullptr) {
			root->left->next = next;
		}
		connect(root->right);
		connect(root->left);
		return root;
	}
};