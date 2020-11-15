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
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr) {
			return head;
		}
		if (head->next == nullptr) {
			return head;
		}
		ListNode* dummy = new ListNode();
		dummy->next = head;
		ListNode* pred = dummy;
		ListNode* tail = head->next;
		while (tail->next != nullptr && tail->next->next != nullptr) {
			pred->next = tail;
			head->next = tail->next;
			tail->next = head;
			pred = head;
			head = head->next;
			tail = head->next;
		}
		if (tail->next == nullptr) {
			pred->next = tail;
			tail->next = head;
			head->next = nullptr;
		}
		else {
			ListNode* real_tail = tail->next;
			pred->next = tail;
			tail->next = head;
			head->next = real_tail;
		}
		return dummy->next;
	}
};