#include <iostream>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
	ListNode* hhead;
public:
	/** @param head The linked list's head.
		Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		hhead = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		int answer;
		ListNode* curr = hhead;
		int cnt = 0;
		while (curr != nullptr) {
			cnt++;
			if (rand() % cnt == 0) {
				answer = curr->val;
			}
			curr = curr->next;
		}
		return answer;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */