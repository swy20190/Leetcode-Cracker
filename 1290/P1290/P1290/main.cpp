#include <iostream>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	int getDecimalValue(ListNode* head) {
		int answer = 0;
		while (head != nullptr) {
			answer = answer * 2 + head->val;
			head = head->next;
		}
		return answer;
	}
};