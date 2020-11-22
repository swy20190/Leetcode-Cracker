#include <stack>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == nullptr) {
			return head;
		}
		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* pred = head;
		for (int i = 0; i < m - 1; i++) {
			pred = pred->next;
		}
		ListNode* succ = head;
		for (int i = 0; i < n; i++) {
			succ = succ->next;
		}
		stack<ListNode*> assist;
		ListNode* curr = pred->next;
		for (int i = 0; i < n - m + 1; i++) {
			assist.push(curr);
			curr = curr->next;
		}
		while (!assist.empty()) {
			pred->next = assist.top();
			assist.pop();
			pred = pred->next;
		}
		pred->next = succ;
		return dummy->next;
	}
};