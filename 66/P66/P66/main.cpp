#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		
		int len = digits.size();
		bool overflow = true;
		for (int i = len - 1; i >= 0; i--) {
			if (digits[i] == 9) {
				digits[i] = 0;
			}
			else {
				digits[i]++;
				overflow = false;
				break;
			}
		}
		if (overflow) {
			digits[0] = 1;
			digits.push_back(0);
		}
		return digits;
	}
};

int main() {
	vector<int> digits = { 4, 3, 2, 1 };
	Solution solution;
	vector<int> ans = solution.plusOne(digits);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}