#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> replaceElements(vector<int>& arr) {
		vector<int> answer = arr;
		answer[arr.size() - 1] = -1;
		for (int i = arr.size() - 2; i >= 0; i--) {
			answer[i] = max(arr[i + 1], answer[i + 1]);
		}
		return answer;
	}
};