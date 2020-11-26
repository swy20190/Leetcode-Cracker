#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {

		quick_sort(nums, 0, nums.size() - 1);
		return nums;
	}

	void quick_sort(vector<int>& nums, int low, int high) {
		if (low >= high) {
			return;
		}
		int index = partition(nums, low, high);
		quick_sort(nums, low, index);
		quick_sort(nums, index + 1, high);
	}

	int partition(vector<int>& nums, int low, int high) {
		srand((int)time(0));
		int index = low + int(rand()%(high - low));
		swap(nums[low], nums[index]);
		int tmp = nums[low];
		while (high > low) {
			while (nums[high] >= tmp && high>low) {
				high--;
			}
			nums[low] = nums[high];
			while (nums[low] <= tmp && low < high) {
				low++;
			}
			nums[high] = nums[low];
		}
		nums[high] = tmp;
		return high;
	}
};