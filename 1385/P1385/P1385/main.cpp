#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		int answer = arr1.size();
		sort(arr2.begin(), arr2.end());
		for (int i = 0; i < (int)arr1.size(); i++) {
			if (upper_bound(arr2.begin(), arr2.end(), arr1[i] + d) - lower_bound(arr2.begin(), arr2.end(), arr1[i] - d)) {
				answer--;
			}
		}
		return answer;
	}
};
