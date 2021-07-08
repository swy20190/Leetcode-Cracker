#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findLucky(vector<int>& arr) {
		int bucket[501] = { 0 };
		for (auto num : arr) {
			bucket[num]++;
		}
		for (int i = 500; i >= 1; i--) {
			if (i == bucket[i]) {
				return i;
			}
		}
		return -1;
	}
};