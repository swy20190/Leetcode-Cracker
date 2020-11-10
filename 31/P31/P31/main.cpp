#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		next_permutation(nums.begin(), nums.end());
	}
};

int main() {
	vector<int> nums;
	nums.push_back(5);
	nums.push_back(1);
	nums.push_back(4);
	Solution solution;
	solution.nextPermutation(nums);
	cout << nums[0] << " " << nums[1] << " " << nums[2] << endl;
}