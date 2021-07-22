#include <iostream>

using namespace std;


class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};


class Solution {
public:
	Node* copyRandomList(Node* head) {
		if(!head) 
			return nullptr;
		Node* ite = head;
		while (ite) { 
			Node* n = new Node(ite->val, ite->next, nullptr);
			Node* c = ite->next;
			ite->next = n;
			ite = c;
		}
		ite = head;
		while (ite) {
			if (ite->random) ite->next->random = ite->random->next;
			ite = ite->next->next;
		}
		ite = head;
		Node* ret = head->next;
		while (ite->next) {
			Node* c = ite->next;
			ite->next = ite->next->next;
			ite = c;
		}
		return ret;
	}
};