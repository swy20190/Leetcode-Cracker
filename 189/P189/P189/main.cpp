#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int real_k = k % nums.size();
		int len = nums.size();
		reverse(nums.begin(), nums.begin() + len - real_k);
		reverse(nums.begin() + len - real_k, nums.end());
		reverse(nums.begin(), nums.end());
	}
};