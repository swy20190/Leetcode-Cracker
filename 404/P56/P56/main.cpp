#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> answer;
		int len = intervals.size();
		if (len == 0) {
			return answer;
		}
		if (len == 1) {
			return intervals;
		}
		sort(intervals.begin(), intervals.end());
		int head = 0;
		int tail = 0;
		while (tail < len) {
			vector<int> tmp = intervals[head];
			while (tail < len && intervals[tail][0] <= tmp[1]) {
				tmp[1] = max(tmp[1], intervals[tail][1]);
				tail++;
			}
			
			answer.push_back(tmp);
			head = tail;
		}
		return answer;
	}
};