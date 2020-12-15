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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == nullptr || k == 1) {
			return head;
		}
		ListNode* header = new ListNode(0, head);
		ListNode* pred = header;
		ListNode* succ = header;
		ListNode* cnt_ptr = header;
		int len = 0;
		while (cnt_ptr->next != nullptr) {
			len++;
			cnt_ptr = cnt_ptr->next;
		}
		cnt_ptr->next = new ListNode(0);
		ListNode* tail = cnt_ptr;
		if (k > len) {
			return head;
		}
		
		while (len >= k) {
			for (int i = 0; i <= k; i++) {
				succ = succ->next;
			}
			ListNode* curr_tail = succ;
			ListNode* pioneer = pred->next->next;
			ListNode* curr = pred->next;
			for (int j = 0;  j < k; j++) {
				curr->next = curr_tail;
				curr_tail = curr;
				curr = pioneer;
				pioneer = pioneer->next;
			}
			pred->next = curr_tail;
			len = len - k;
			for (int i = 0; i < k; i++) {
				pred = pred->next;
				succ = pred;
			}
		}
		
		if (len == 0) {
			for (int i = 0; i < k - 1; i++) {
				tail = tail->next;
			}
			tail->next = nullptr;
		}
		else {
			tail->next = nullptr;
		}
		return header->next;
	}
};