#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool canBeEqual(vector<int>& target, vector<int>& arr) {
		if (target.size() != arr.size()) {
			return false;
		}
		sort(target.begin(), target.end());
		sort(arr.begin(), arr.end());
		return target == arr;
	}
};