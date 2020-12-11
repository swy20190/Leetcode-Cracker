#include <vector>

using namespace std;


class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		int a_min = m;
		int b_min = n;
		for (auto& op : ops) {
			if (op[0] < a_min) {
				a_min = op[0];
			}
			if (op[1] < b_min) {
				b_min = op[1];
			}
		}
		return a_min * b_min;
	}
};