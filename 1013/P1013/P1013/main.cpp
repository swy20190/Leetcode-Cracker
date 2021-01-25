#include <vector>

using namespace std;

class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& arr) {
		int sum = 0;
		for (auto num : arr) {
			sum += num;
		}
		if (sum % 3 != 0) {
			return false;
		}
		sum /= 3;
		int left = 0;
		int tmp_l = 0;
		bool find_l = false;
		bool find_r = false;
		for (int i = 0; i < arr.size(); i++) {
			tmp_l += arr[i];
			if (tmp_l == sum) {
				left = i;
				find_l = true;
				break;
			}
		}
		if (!find_l) {
			return false;
		}
		int tmp_r = 0;
		int right = 0;
		for (int i = arr.size() - 1; i >= 0; i--) {
			tmp_r += arr[i];
			if (tmp_r == sum) {
				right = i;
				find_r = true;
				break;
			}
		}
		if (!find_r) {
			return false;
		}
		return right - left > 1;
	}
};