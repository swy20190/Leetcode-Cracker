#include <iostream>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};