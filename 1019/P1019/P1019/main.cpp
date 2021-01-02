#include <vector>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	vector<int> nextLargerNodes(ListNode* head) {
		vector<int> answer;
		if (head == nullptr || head->next == nullptr) {
			answer.push_back(0);
			return answer;
		}
		ListNode* curr = head->next;
		while (head != nullptr && curr != nullptr) {
			int curr_val = head->val;
			while (curr != nullptr) {
				if (curr_val < curr->val) {
					curr_val = curr->val;
					break;
				}
				curr = curr->next;
			}
			if (curr_val == head->val) {
				curr_val = 0;
			}
			answer.push_back(curr_val);
			head = head->next;
			curr = head->next;
		}
		answer.push_back(0);
		return answer;
	}
};