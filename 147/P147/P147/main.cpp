#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* dummy = new ListNode(INT_MIN);
		dummy->next = head;
		ListNode* pred = dummy;
		ListNode* curr = head;
		while (curr != nullptr) {
			if (curr->val >= pred->val) {
				curr = curr->next;
				pred = pred->next;
			}
			else {
				pred->next = curr->next;
				ListNode* start = dummy;
				while (start->next->val <= curr->val) {
					start = start->next;
				}
				curr->next = start->next;
				start->next = curr;
				curr = pred->next;
			}
		}
		return dummy->next;
	}
};