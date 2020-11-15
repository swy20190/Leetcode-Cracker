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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode();
		ListNode* curr = dummy;
		while (l1 != nullptr || l2 != nullptr) {
			if (l1 != nullptr && l2 != nullptr) {
				if (l1->val < l2->val) {
					curr->next = l1;
					curr = curr->next;
					l1 = l1->next;
				}
				else {
					curr->next = l2;
					curr = curr->next;
					l2 = l2->next;
				}
			}
			else if (l1 == nullptr) {
				curr->next = l2;
				curr = curr->next;
				l2 = l2->next;
			}
			else {
				curr->next = l1;
				curr = curr->next;
				l1 = l1->next;
			}
		}
		return dummy->next;
	}
};