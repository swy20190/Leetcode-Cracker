#include <iostream>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* tail = head;
		if (head == nullptr) {
			return head;
		}
		int len = 1;
		while (tail->next != nullptr) {
			tail = tail->next;
			len++;
		}
		tail->next = head;
		ListNode* new_head = head;
		ListNode* new_tail = tail;
		for (int i = 0; i < len-k%len; i++) {
			new_head = new_head->next;
			new_tail = new_tail->next;
		}
		new_tail->next = nullptr;
		return new_head;
	}
};