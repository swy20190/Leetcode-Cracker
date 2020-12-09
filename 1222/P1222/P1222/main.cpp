#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
		int **map = new int*[8];
		for (int i = 0; i < 8; i++) {
			map[i] = new int[8];
		}
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				map[i][j] = 0;
			}
		}
		for (auto& coor : queens) {
			map[coor[0]][coor[1]] = 1;
		}
		vector<vector<int>> answer;
		for (int i = king[1] + 1; i < 8; i++) {
			if (map[king[0]][i] == 1) {
				vector<int> tmp;
				tmp.push_back(king[0]);
				tmp.push_back(i);
				answer.push_back(tmp);
				break;
			}
		}
		for (int i = king[1] - 1; i >= 0; i--) {
			if (map[king[0]][i] == 1) {
				vector<int> tmp;
				tmp.push_back(king[0]);
				tmp.push_back(i);
				answer.push_back(tmp);
				break;
			}
		}
		for (int i = king[1] + 1; i < min(8, king[0] + king[1] + 1); i++) {
			if (map[king[0] + king[1] - i][i] == 1) {
				vector<int> tmp;
				tmp.push_back(king[0] + king[1] - i);
				tmp.push_back(i);
				answer.push_back(tmp);
				break;
			}
		}
		for (int i = king[1] - 1; i >= max(0, king[0]+king[1]-7); i--) {
			if (map[king[0] + king[1]-i][i] == 1) {
				vector<int> tmp;
				tmp.push_back(king[0] + king[1] - i);
				tmp.push_back(i);
				answer.push_back(tmp);
				break;
			}
		}
		for (int i = king[0] + 1; i < 8; i++) {
			if (map[i][king[1]] == 1) {
				vector<int> tmp;
				tmp.push_back(i);
				tmp.push_back(king[1]);
				answer.push_back(tmp);
				break;
			}
		}
		for (int i = king[0] - 1; i >= 0; i--) {
			if (map[i][king[1]] == 1) {
				vector<int> tmp;
				tmp.push_back(i);
				tmp.push_back(king[1]);
				answer.push_back(tmp);
				break;
			}
		}
		for (int i = king[1] + 1; i < min(8, king[1] - king[0] + 8); i++) {
			if (map[i + king[0] - king[1]][i] == 1) {
				vector<int> tmp;
				tmp.push_back(i + king[0] - king[1]);
				tmp.push_back(i);
				answer.push_back(tmp);
				break;
			}
		}
		for (int i = king[1] - 1; i >= max(0, king[1] - king[0]); i--) {
			if (map[i + king[0] - king[1]][i] == 1) {
				vector<int> tmp;
				tmp.push_back(i + king[0] - king[1]);
				tmp.push_back(i);
				answer.push_back(tmp);
				break;
			}
		}
		return answer;
	}
};