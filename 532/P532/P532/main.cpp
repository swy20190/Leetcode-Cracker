#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if (k < 0) {
			return 0;
		}
		unordered_map<int, int> m;
		for (auto num : nums) {
			m[num]++;
		}
		int answer = 0;
		if (k == 0) {
			for (auto p : m) {
				if (p.second > 1) {
					answer++;
				}
			}
			return answer;
		}
		for (auto p : m) {
			if (m.find(p.first + k) != m.end()) {
				answer++;
			}
		}
		return answer;
	}
};