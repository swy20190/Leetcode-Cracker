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
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
		ListNode* pred = list1;
		ListNode* succ = list1;
		for (int i = 0; i < a-1; i++) {
			pred = pred->next;
		}
		for (int i = 0; i <= b; i++) {
			succ = succ->next;
		}
		pred->next = list2;
		while (pred->next != nullptr) {
			pred = pred->next;
		}
		pred->next = succ;
		return list1;
	}
};