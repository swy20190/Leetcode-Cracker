#include <vector>

using namespace std;

class Solution {
public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		int len = coordinates.size();
		if (len <= 2) {
			return true;
		}
		if (coordinates[0][0] == coordinates[1][0]) {
			int common_x = coordinates[0][0];
			for (auto coord : coordinates) {
				if (coord[0] != common_x) {
					return false;
				}
			}
			return true;
		}
		else {
			double common_k = (coordinates[1][1] - coordinates[0][1]) / (1.0*(coordinates[1][0] - coordinates[0][0]));
			for (int i = 1; i < len;i++) {
				auto coord = coordinates[i];
				if (coord[0] == coordinates[0][0]) {
					return false;
				}
				if ((coord[1] - coordinates[0][1]) / (1.0*(coord[0] - coordinates[0][0])) != common_k) {
					return false;
				}
			}
			return true;
		}
	}
};