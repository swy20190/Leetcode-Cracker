#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		vector<vector<int>> answer;
		sort(arr.begin(), arr.end());
		int minDiff = INT_MAX;
		for (int i = 1; i < arr.size(); i++) {
			int diff = arr[i] - arr[i - 1];
			if (diff < minDiff) {
				minDiff = diff;
				answer.clear();
				vector<int> pair;
				pair.push_back(arr[i - 1]);
				pair.push_back(arr[i]);
				answer.push_back(pair);
			}
			else if (diff == minDiff) {
				vector<int> pair;
				pair.push_back(arr[i - 1]);
				pair.push_back(arr[i]);
				answer.push_back(pair);
			}
		}
		return answer;
	}
};