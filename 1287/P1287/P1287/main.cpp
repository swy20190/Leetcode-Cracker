#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		int len = arr.size();
		int step = len / 4;
		for (int i = 0; i < len - step; i++) {
			if (arr[i] == arr[i + step]) {
				return arr[i];
			}
		}
		return -1;
	}
};