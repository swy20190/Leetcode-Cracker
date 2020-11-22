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
		 while (succ != nullptr) {
			 if (pred->val != succ->val) {
				 pred = pred->next;
				 succ = succ->next;
			 }
			 else {
				 while (succ != nullptr && succ->val == pred->val) {
					 succ = succ->next;
				 }
				 if (succ == nullptr) {
					 pred->next = nullptr;
				 }
				 else {
					 pred->next = succ;
					 pred = pred->next;
					 succ = succ->next;
				 }
			 }
		 }
		 return head;
	 }
 };