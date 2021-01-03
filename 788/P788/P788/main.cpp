#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int rotatedDigits(int N) {
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (isValid(i)) {
				cnt++;
			}
		}
		return cnt;
	}

	bool isValid(int N) {
		string numStr = std::to_string(N);
		int cnt_2569 = 0;
		for (char c : numStr) {
			if (c == '2' || c == '5' || c == '6' || c == '9') {
				cnt_2569++;
			}
			if (c != '2'&&c != '5'&&c != '6'&&c != '9'&&c != '0'&&c != '1'&&c != '8') {
				return false;
			}
		}
		return cnt_2569 > 0;
	}
};