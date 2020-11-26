#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int len = nums.size();
		if (len < 2) {
			return 0;
		}
		int min = INT_MAX;
		int max = INT_MIN;
		for (int num : nums) {
			if (num > max) {
				max = num;
			}
			if (num < min) {
				min = num;
			}
		}
		if (max == min) {
			return 0;
		}
		double bucket_size = (max - min)*1.0 / len;
		int* bucket_min = new int[len + 1];
		int* bucket_max = new int[len + 1];
		bool* bucket_empty = new bool[len + 1];
		for (int i = 0; i <= len; i++) {
			bucket_empty[i] = true;

		}
		for (int num : nums) {
			//int index = 0;
			int index = (int)((num - min) / bucket_size);

			if (bucket_empty[index]) {
				bucket_min[index] = num;
				bucket_max[index] = num;
				bucket_empty[index] = false;
			}
			else {
				if (num > bucket_max[index]) {
					bucket_max[index] = num;
				}
				if (num < bucket_min[index]) {
					bucket_min[index] = num;
				}
			}
		}
		int answer = INT_MIN;
		int pred = 0;
		for (int i = 0; i <= len; i++) {
			if (bucket_empty[i]) {
				pred = i - 1;
				break;
			}
		}
		int curr = pred + 1;
		while (curr <= len) {
			if (bucket_empty[curr]) {
				curr++;
			}
			else {
				int diff = bucket_min[curr] - bucket_max[pred];
				if (diff > answer) {
					answer = diff;
				}
				pred = curr;
				while (pred <= len) {
					if (!bucket_empty[pred]) {
						pred++;
					}
					else {
						pred--;
						break;
					}
				}
				curr = pred + 1;
			}
		}
		return answer;
	}
};


int main() {
	Solution solution;
	vector<int> nums = { 1, 3, 100};
	cout << solution.maximumGap(nums);
}