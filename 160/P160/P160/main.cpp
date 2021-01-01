#include <iostream>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* curr_a = headA;
		ListNode* curr_b = headB;
		while (curr_a != curr_b) {
			if (curr_a != nullptr) {
				curr_a = curr_a->next;
			}
			else {
				curr_a = headB;
			}
			if (curr_b != nullptr) {
				curr_b = curr_b->next;
			}
			else {
				curr_b = headA;
			}
		}
		return curr_a;
	}
};