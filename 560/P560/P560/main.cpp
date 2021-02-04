#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		long curr = 0;
		int answer = 0;
		unordered_map<long, int> m;
		m[0] = 1;
		for (auto num : nums) {
			curr += num;
			answer += m[curr - k];
			m[curr]++;
		}
		return answer;
	}
};