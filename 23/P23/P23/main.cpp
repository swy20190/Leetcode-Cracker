#include <vector>
#include <queue>


using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {

	struct cmp {
		bool operator()(ListNode* a, ListNode* b) {
			return a->val > b->val;
		}
	};
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) {
			return nullptr;
		}
		ListNode* ret = new ListNode();
		ListNode* ptr = ret;
		priority_queue<ListNode*, vector<ListNode*>, cmp> p_q;
		int len = lists.size();
		for (int i = 0; i < len; i++) {
			if (lists[i] != nullptr) {
				p_q.push(lists[i]);
			}
		}
		while (!p_q.empty()) {
			ListNode* curr = p_q.top();
			ptr->next = new ListNode(curr->val);
			ptr = ptr->next;
			curr = curr->next;
			p_q.pop();
			if (curr != nullptr) {
				p_q.push(curr);
			}
		}

		return ret->next;
	}
};