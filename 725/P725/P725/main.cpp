#include <vector>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		vector<ListNode*> answer;
		ListNode* len_ptr = root;
		int len = 0;
		while (len_ptr != nullptr) {
			len_ptr = len_ptr->next;
			len++;
		}
		if (len == 0) {
			for (int i = 0; i < k; i++) {
				answer.push_back(nullptr);
			}
			return answer;
		}
		int base_len = len / k;
		int longer = len % k;
		ListNode* divider = root;
		for (int i = 0; i < k; i++) {
			answer.push_back(divider);
			ListNode* tail = divider;
			for (int j = 0; j < base_len-1; j++) {
				tail = tail->next;
			}
			if (longer > 0) {
				if (tail != nullptr && base_len>=1) {
					tail = tail->next;
				}
				longer--;
			}
			if (tail != nullptr) {
				divider = tail->next;
				tail->next = nullptr;
			}
		}
		return answer;
	}
};