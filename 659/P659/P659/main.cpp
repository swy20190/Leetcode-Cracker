#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPossible(vector<int>& nums) {
		unordered_map<int, int> numsCnt;
		unordered_map<int, int> numsEndSeqCnt;

		for (auto num : nums) {
			numsCnt[num] += 1;
		}

		for (auto num : nums) {
			if (numsCnt[num] == 0) {
				continue;
			}
			numsCnt[num]--;
			if (numsEndSeqCnt.count(num - 1) && numsEndSeqCnt[num - 1] > 0) {
				numsEndSeqCnt[num - 1]--;
				numsEndSeqCnt[num]++;
			}
			else if (numsCnt.count(num + 1) && numsCnt[num + 1] > 0 && numsCnt.count(num + 2) && numsCnt[num + 2] > 0) {
				numsCnt[num + 1]--;
				numsCnt[num + 2]--;
				numsEndSeqCnt[num + 2]++;
			}
			else {
				return false;
			}
		}
		return true;
	}
};