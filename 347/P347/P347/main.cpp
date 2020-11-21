#include <vector>
#include <map>
#include <queue>

using namespace std;


class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		int len = nums.size();
		vector<int> answer;
		map<int, int> count_map;
		for (int i = 0; i < len; i++) {
			count_map[nums[i]] ++;
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		for (auto& pair : count_map) {
			pq.emplace(pair.second, pair.first);
			if (pq.size() > k) {
				pq.pop();
			}
		}
		while (!pq.empty()) {
			answer.push_back(pq.top().second);
			pq.pop();
		}

		return answer;
	}
};