#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		unordered_map<int, int> m;
		for (auto row : wall) {
			int sum = 0;
			for (int i = 0; i < row.size() - 1; i++) {
				sum += row[i];
				m[sum]++;
			}
		}
		int answer = 0;
		for (auto t : m) {
			answer = max(answer, t.second);
		}
		return wall.size() - answer;
	}
};