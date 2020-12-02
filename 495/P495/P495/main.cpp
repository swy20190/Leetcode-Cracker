#include <vector>

using namespace std;


class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int len = timeSeries.size();
		if (len == 0) {
			return 0;
		}
		if (len == 1) {
			return duration;
		}
		
		int answer = 0;
		for (int i = 1; i < len; i++) {
			int diff = timeSeries[i] - timeSeries[i - 1];
			if (diff < duration) {
				answer += diff;
			}
			else {
				answer += duration;
			}
		}
		answer += duration;
		return answer;
	}
};