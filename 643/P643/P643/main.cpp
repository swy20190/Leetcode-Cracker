#include <vector>

using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int len = nums.size();
		int max_sum = 0;
		for (int i = 0; i < k; i++) {
			max_sum += nums[i];
		}
		int curr_sum = max_sum;
		for (int i = 1; i < len +1 - k; i++) {
			curr_sum -= nums[i - 1];
			curr_sum += nums[i + k - 1];
			if (curr_sum > max_sum) {
				max_sum = curr_sum;
			}
		}
		return (1.0*max_sum) / (1.0*k);
	}
};