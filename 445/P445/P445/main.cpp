#include<stack>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> num1;
		stack<int> num2;
		ListNode* answer = nullptr;
		while (l1 != nullptr) {
			num1.push(l1->val);
			l1 = l1->next;
		}
		while (l2 != nullptr) {
			num2.push(l2->val);
			l2 = l2->next;
		}
		int carry = 0;
		while (!num1.empty() || !num2.empty() || carry!=0) {
			int tmp = 0;
			if (!num1.empty()) {
				tmp += num1.top();
				num1.pop();
			}
			if (!num2.empty()) {
				tmp += num2.top();
				num2.pop();
			}
			tmp += carry;
			carry = 0;
			if (tmp >= 10) {
				tmp -= 10;
				carry = 1;
			}
			ListNode* curr = new ListNode(tmp);
			curr->next = answer;
			answer = curr;
		}
		return answer;
	}
};