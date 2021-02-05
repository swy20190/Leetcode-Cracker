#include <vector>

using namespace std;

class NumArray {
	vector<int> front_sum;
public:
	NumArray(vector<int>& nums) {
		int tmp = 0;
		front_sum.push_back(0);
		for (auto num : nums) {
			tmp += num;
			front_sum.push_back(tmp);
		}
	}

	int sumRange(int i, int j) {
		return front_sum[j + 1] - front_sum[i];
	}
};