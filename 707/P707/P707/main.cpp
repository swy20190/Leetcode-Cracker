#include <iostream>

using namespace std;

class MListNode {
public:
	int val;
	MListNode* pred;
	MListNode* succ;
	MListNode(int val) :val(val) {};
};

class MyLinkedList {
	MListNode* header;
	MListNode* trailer;
	int size = 0;
public:
	/** Initialize your data structure here. */
	MyLinkedList() {
		header = new MListNode(0);
		trailer = new MListNode(0);
		header->succ = trailer;
		trailer->pred = header;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		MListNode* curr = header->succ;
		for (int i = 0; i < index; i++) {
			if (curr == trailer) {
				return -1;
			}
			curr = curr->succ;
		}
		if (curr == trailer) {
			return -1;
		}
		return curr->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		MListNode* tmpNode = new MListNode(val);
		tmpNode->succ = header->succ;
		tmpNode->pred = header;
		header->succ = tmpNode;
		tmpNode->succ->pred = tmpNode;
		size++;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		MListNode* tmpNode = new MListNode(val);
		tmpNode->succ = trailer;
		tmpNode->pred = trailer->pred;
		trailer->pred = tmpNode;
		tmpNode->pred->succ = tmpNode;
		size++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index < 0) {
			addAtHead(val);
		}
		else if (index == size) {
			addAtTail(val);
		}
		else if (index < size) {
			MListNode* curr = header;
			for (int i = 0; i < index; i++) {
				curr = curr->succ;
			}
			MListNode* tmpNode = new MListNode(val);
			tmpNode->succ = curr->succ;
			tmpNode->pred = curr;
			curr->succ = tmpNode;
			tmpNode->succ->pred = tmpNode;
			size++;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < size && index >= 0) {
			MListNode* curr = header;
			for (int i = 0; i < index; i++) {
				curr = curr->succ;
			}
			MListNode* del = curr->succ;
			curr->succ = del->succ;
			curr->succ->pred = curr;
			delete(del);
			size--;
		}
	}
};