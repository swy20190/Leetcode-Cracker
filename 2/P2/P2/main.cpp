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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* answer = new ListNode();
		ListNode* ptr = answer;
		int carrier = 0;
		while (l1 != nullptr || l2 != nullptr) {
			if (l1 != nullptr && l2 != nullptr) {
				int sum = l1->val + l2->val + carrier;
				carrier = 0;
				if (sum > 9) {
					sum = sum - 10;
					carrier = 1;
				}
				ptr->next = new ListNode(sum);
				ptr = ptr->next;
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l1 == nullptr && l2 != nullptr) {
				int sum = l2->val + carrier;
				carrier = 0;
				if (sum > 9) {
					sum = sum - 10;
					carrier = 1;
				}
				ptr->next = new ListNode(sum);
				ptr = ptr->next;
				l2 = l2->next;
			}
			else if (l1 != nullptr && l2 == nullptr) {
				int sum = l1->val + carrier;
				carrier = 0;
				if (sum > 9) {
					sum = sum - 10;
					carrier = 1;
				}
				ptr->next = new ListNode(sum);
				ptr = ptr->next;
				l1 = l1->next;
			}
		}
		if (carrier > 0) {
			ptr->next = new ListNode(carrier);
		}
		return answer->next;
	}
};

int main() {
	ListNode* l1 = new ListNode();
	ListNode* l2 = new ListNode();
	ListNode* ptr1 = l1;
	ListNode* ptr2 = l2;
	ptr1->next = new ListNode(2);
	ptr1 = ptr1->next;
	ptr1->next = new ListNode(4);
	ptr1 = ptr1->next;
	ptr1->next = new ListNode(3);
	ptr1 = ptr1->next;
	ptr2->next = new ListNode(5);
	ptr2 = ptr2->next;
	ptr2->next = new ListNode(6);
	ptr2 = ptr2->next;
	ptr2->next = new ListNode(4);
	ptr2 = ptr2->next;

	Solution solution;
	ListNode* ans = solution.addTwoNumbers(l1->next, l2->next);
	while (ans != nullptr) {
		cout << ans->val << " ";
		ans = ans->next;
	}
}