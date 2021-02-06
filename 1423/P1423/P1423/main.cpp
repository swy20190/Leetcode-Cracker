#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int sum = 0;
		int len = cardPoints.size();
		for (auto p : cardPoints) {
			sum += p;
		}
		if (len == k) {
			return sum;
		}
		int window_size = len - k;
		int left = 0;
		int right = window_size;
		int curr_sum = 0;
		for (int i = 0; i < right; i++) {
			curr_sum += cardPoints[i];
		}
		int min_sum = curr_sum;
		while (right < len) {
			curr_sum += cardPoints[right];
			curr_sum -= cardPoints[left];
			right++;
			left++;
			min_sum = min(min_sum, curr_sum);
		}
		return sum - min_sum;
	}
};