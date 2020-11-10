

 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* front = new ListNode();
		front->next = head;
		ListNode* left = head;
		ListNode* right = head;
		for (int i = 0; i < n-1; i++) {
			right = right->next;
		}
		while (right->next != nullptr) {
			front = front->next;
			left = left->next;
			right = right->next;
		}
		if (left == head) {
			return head->next;
		}
		front->next = left->next;
		return head;
	}
};