#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int len = nums.size();
		my_quick_sort(nums, 0, len-1);
		return nums[len - k];
	}

	void my_quick_sort(vector<int>& nums, int start, int end) {
		if (start < end) {
			int pivot = partition(nums, start, end);
			my_quick_sort(nums, start, pivot - 1);
			my_quick_sort(nums, pivot + 1, end);
		}
	}

	int partition(vector<int>& nums, int start, int end) {
		srand((int)time(0));
		int random_index = rand() % (end - start) + start;
		swap(nums[start], nums[random_index]);
		int tmp = nums[start];
		while (end > start) {
			while (end > start && nums[end] >= tmp) {
				end--;
			}
			nums[start] = nums[end];
			while (start < end && nums[start] <= tmp) {
				start++;
			}
			nums[end] = nums[start];
		}
		nums[start] = tmp;
		return start;
	}
};