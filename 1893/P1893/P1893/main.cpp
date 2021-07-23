#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	bool isCovered(vector<vector<int>>& ranges, int left, int right) {
		vector<int> cnt(52);
		for (auto &r : ranges) {
			++cnt[r[0]];
			--cnt[r[1] + 1];
		}
		int pre = 0;
		for (int i = 0; i < 52; i++) {
			pre += cnt[i];
			if (i >= left && i <= right && pre <= 0) {
				return false;
			}
		}
		return true;
	}
};