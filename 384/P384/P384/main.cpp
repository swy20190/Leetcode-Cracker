#include <vector>

using namespace std;

class Solution {
	vector<int> original;
public:
	Solution(vector<int>& nums) {
		original = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return original;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> tmp = original;
		for (int i = 0; i < tmp.size(); i++) {
			int rand_index = rand() % (i + 1);
			if (rand_index != i) {
				swap(tmp[i], tmp[rand_index]);
			}
		}
		return tmp;
	}
};