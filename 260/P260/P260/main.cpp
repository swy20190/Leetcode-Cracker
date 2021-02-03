#include <vector>

using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		long xxx = 0;
		for (auto num : nums) {
			xxx = xxx ^ num;
		}
		long diff = xxx & (~xxx + 1);
		int a = 0;
		int b = 0;
		for (auto num : nums) {
			if (num&diff) {
				a = a ^ num;
			}
			else {
				b = b ^ num;
			}
		}
		return { a, b };
	}
};