#include <iostream>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode* smaller = new ListNode(0);
		ListNode* larger = new ListNode(0);
		ListNode* curr = head;
		ListNode* s_curr = smaller;
		ListNode* l_curr = larger;
		while (curr != nullptr) {
			if (curr->val < x) {
				s_curr->next = curr;
				s_curr = s_curr->next;
			}
			else {
				l_curr->next = curr;
				l_curr = l_curr->next;
			}
			curr = curr->next;
		}
		s_curr->next = larger->next;
		l_curr->next = nullptr;
		return smaller->next;
	}
};