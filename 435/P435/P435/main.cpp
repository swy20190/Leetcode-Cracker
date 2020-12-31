#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int len = intervals.size();
		if (len == 0) {
			return 0;
		}
		if (len == 1) {
			return 0;
		}
		sort(intervals.begin(), intervals.end());
		int rest = 1;
		int interval_ptr = 0;
		int current_tail = intervals[0][1];

		while (interval_ptr < len) {


			if (intervals[interval_ptr][0] >= current_tail) {
				current_tail = intervals[interval_ptr][1];
				rest++;
				interval_ptr++;
			}
			else {
				if (intervals[interval_ptr][1] < current_tail) {
					current_tail = intervals[interval_ptr][1];
				}
				interval_ptr++;
			}
		}
		return len - rest;
	}
};