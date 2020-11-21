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
	ListNode* sortList(ListNode* head) {
		if (head == nullptr) {
			return head;
		}
		ListNode* dummy = new ListNode(INT_MIN);
		dummy->next = head;

		ListNode* pred = dummy;
		ListNode* curr = head;
		ListNode* insert = dummy;
		while (curr != nullptr) {
			if (pred->val <= curr->val) {
				pred = pred->next;
				curr = curr->next;
			}
			else {
				pred->next = curr->next;
				insert = dummy;
				while (insert->next->val <= curr->val) {
					insert = insert->next;
				}
				curr->next = insert->next;
				insert->next = curr;
				curr = pred->next;
			}
		}
		return dummy->next;
	}
};

