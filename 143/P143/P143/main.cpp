#include <iostream>
#include <stack>

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
	 void reorderList(ListNode* head) {
		 stack<ListNode*> tmp;
		 ListNode* curr = head;
		 if (head == nullptr) {
			 return;
		 }
		 if (head->next == nullptr) {
			 return;
		 }
		 while (curr != nullptr) {
			 tmp.push(curr);
			 curr = curr->next;
		 }
		 ListNode* dummy = new ListNode();
		 dummy->next = head;
		 ListNode* front = dummy;
		 while (head->next != nullptr&&head->next->next != nullptr) {
			 front->next = head;
			 head = head->next;
			 front = front->next;
			 front->next = tmp.top();
			 front = front->next;

			 tmp.pop();
			 tmp.top()->next = nullptr;
		 }
		 front->next = head;
		 head = dummy->next;
		 dummy->next = nullptr;
	 }
 };