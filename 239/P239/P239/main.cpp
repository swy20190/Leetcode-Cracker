#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int len = nums.size();
		deque<int> q;
		for (int i = 0; i < k; i++) {
			while (!q.empty() && nums[i] >= nums[q.back()]) {
				q.pop_back();
			}
			q.push_back(i);
		}

		vector<int> answer = { nums[q.front()] };
		for (int i = k; i < len; i++) {
			while (!q.empty() && nums[i] >= nums[q.back()]) {
				q.pop_back();
			}
			q.push_back(i);
			while (q.front() <= i - k) {
				q.pop_front();
			}
			answer.push_back(nums[q.front()]);
		}
		return answer;
	}
};