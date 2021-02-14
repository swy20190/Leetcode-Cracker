#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findMinDifference(vector<string>& timePoints) {
		if (timePoints.size() > 1440) {
			return 0;
		}
		vector<int> times;
		for (auto t : timePoints) {
			int hour = 10 * (t[0] - '0') + (t[1] - '0');
			int min = 10 * (t[3] - '0') + (t[4] - '0');
			times.push_back(60 * hour + min);
		}
		sort(times.begin(), times.end());
		times.push_back(times[0] + 24 * 60);
		int answer = INT_MAX;
		for (int i = 1; i < times.size(); i++) {
			answer = min(answer, times[i] - times[i - 1]);
		}
		return answer;
	}
};