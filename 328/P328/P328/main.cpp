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
	ListNode* oddEvenList(ListNode* head) {
		ListNode* answer = head;
		if (head == nullptr) {
			return head;
		}
		if (head->next == nullptr) {
			return head;
		}
		ListNode* tail = head->next;
		if (tail->next == nullptr) {
			return head;
		}
		ListNode* pivot = tail;
		while (tail->next != nullptr) {
			head->next = tail->next;
			head = head->next;
			if (head->next == nullptr) {
				tail->next = nullptr;
				break;
			}
			tail->next = head->next;
			tail = tail->next;
		}
		head->next = pivot;
		return answer;
	}
};

int main() {
	ListNode* head = new ListNode(1);
	ListNode* curr = head;
	for (int i = 0; i < 4; i++) {
		curr->next = new ListNode(i + 2);
		curr = curr->next;
	}
	Solution solution;
	ListNode* ans = solution.oddEvenList(head);
	while (ans != nullptr) {
		cout << ans->val << " ";
		ans = ans->next;
	}
}