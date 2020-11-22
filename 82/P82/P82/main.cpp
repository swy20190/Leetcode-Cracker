#include <iostream>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 class Solution {
 public:
	 ListNode* deleteDuplicates(ListNode* head) {
		 if (head == nullptr) {
			 return head;
		 }
		 if (head->next == nullptr) {
			 return head;
		 }
		 ListNode* pred = head;
		 ListNode* succ = head->next;
		 ListNode* dummy = new ListNode(0);
		 dummy->next = head;
		 ListNode* ppred = dummy;
		 while (succ != nullptr) {
			 if (pred->val != succ->val) {
				 pred = pred->next;
				 succ = succ->next;
				 ppred = ppred->next;
			 }
			 else {
				 while (succ != nullptr && succ->val == pred->val) {
					 succ = succ->next;
				 }
				 if (succ == nullptr) {
					 pred = nullptr;
					 ppred->next = nullptr;
				 }
				 else {
					 ppred->next = succ;
					 pred = succ;
					 succ = succ->next;
				 }
			 }
		 }
		 return dummy->next;
	 }
 };