#include <vector>

using namespace std;


class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> answer;
		int len = pow(2, n);
		for (int i = 0; i < len; i++) {
			answer.push_back(i ^ (i >> 1));
		}
		return answer;
	}
};