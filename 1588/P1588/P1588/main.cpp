#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int sumOddLengthSubarrays(vector<int>& arr) {
		vector<int> acc(arr.size() + 1, 0);
		for (int i = 1; i < acc.size(); i++) {
			acc[i] = acc[i - 1] + arr[i - 1];
		}

		int sum = 0;
		for (int len = 1; len < acc.size(); len += 2) {
			for (int i = len; i < acc.size(); i++) {
				sum += acc[i] - acc[i - len];
			}
		}
		return sum;
	}
};