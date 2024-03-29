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
		if (headA == NULL || headB == NULL) {
			return NULL;
		}
		ListNode* n1 = headA;
		ListNode* n2 = headB;
		while (n1 != n2) {
			n1 = n1 == NULL ? headB : n1->next;
			n2 = n2 == NULL ? headA : n2->next;
		}
		return n1;
	}
};