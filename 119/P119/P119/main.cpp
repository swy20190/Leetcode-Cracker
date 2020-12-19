#include <vector>

using namespace std;


class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> answer;
		answer.push_back(1);
		if (rowIndex == 0) {
			return answer;
		}
		answer.push_back(1);
		if (rowIndex == 1) {
			return answer;
		}
		for (int i = 1; i < rowIndex; i++) {
			vector<int> tmp = answer;
			for (int i = 1; i < tmp.size(); i++) {
				tmp[i] = answer[i - 1] + answer[i];
			}
			tmp.push_back(1);
			answer = tmp;
		}
		return answer;
	}
};