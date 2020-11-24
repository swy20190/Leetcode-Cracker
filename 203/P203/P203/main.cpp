#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummy = new ListNode(0);
		ListNode* curr = dummy;
		
		while (head != nullptr && head->next != nullptr) {
			if (head->val == val) {
				ListNode* del = head;
				head = head->next;
				delete(del);
			}
			else {
				curr->next = head;
				curr = curr->next;
				head = head->next;
			}
		}
		if (head != nullptr) {
			if (head->val == val) {
				curr->next = nullptr;
			}
			else {
				curr->next = head;
			}
		}
		return dummy->next;
	}
};