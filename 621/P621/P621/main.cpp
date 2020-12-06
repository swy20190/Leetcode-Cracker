#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int> cnt(26, 0);
		for (char task : tasks) {
			cnt[task - 'A']++;
		}
		sort(cnt.begin(), cnt.end());
		int maxCnt = 0;
		for (int i = 25; i >= 0; i--) {
			if (cnt[i] != cnt[25]) {
				break;
			}
			maxCnt++;
		}
		return max((cnt[25] - 1)*(n + 1) + maxCnt, (int)tasks.size());
	}
};