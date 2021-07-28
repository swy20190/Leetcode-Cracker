#include <string>

using namespace std;

class Solution {
public:
	int balancedStringSplit(string s) {
		int L_cnt = 0;
		int R_cnt = 0;
		int answer = 0;
		for (char c : s) {
			if (c == 'L') {
				L_cnt++;
			}
			else {
				R_cnt++;
			}
			if (L_cnt == R_cnt) {
				answer++;
			}
		}
		return answer;
	}
};