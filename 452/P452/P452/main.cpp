#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.empty()) {
			return 0;
		}
		sort(begin(points), end(points), [](auto& p1, auto& p2) {
			return p1[1] < p2[1]; });
		int answer = 1;
		int upper_bound = points[0][1];
		for (auto& point : points) {
			if (point[0] > upper_bound) {
				answer++;
				upper_bound = point[1];
			}
		}
		return answer;
	}
};