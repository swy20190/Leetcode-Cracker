#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int heightChecker(vector<int>& heights) {
		vector<int> sorted_h = heights;
		sort(sorted_h.begin(), sorted_h.end());
		int answer = 0;
		for (int i = 0; i < heights.size(); i++) {
			if (heights[i] != sorted_h[i]) {
				answer++;
			}
		}
		return answer;
	}
};