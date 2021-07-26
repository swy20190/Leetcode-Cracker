#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
		int* index = new int[101];
		for (int i = 0; i < arr.size(); i++) {
			index[arr[i]] = i;
		}
		for (auto& p : pieces) {
			int idx = index[p[0]];
			for (int i = 0; i < p.size(); i++) {
				if (idx + i >= arr.size() || arr[idx + i] != p[i]) {
					return false;
				}
			}
		}
		return true;
	}
};