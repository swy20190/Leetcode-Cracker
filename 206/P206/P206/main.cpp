#include <iostream>

using namespace std;



 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr) {
			return head;
		}
		if (head->next == nullptr) {
			return head;
		}
		ListNode* tail = reverseList(head->next);
		ListNode* ret = tail;
		while (tail->next != nullptr) {
			tail = tail->next;
		}
		tail->next = head;
		head->next = nullptr;
		return ret;
	}
};