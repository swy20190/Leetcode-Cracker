#include <string>

using namespace std;

class Solution {
public:
	int magicalString(int n) {
		string magic = "122";
		int add = 2;
		int idx = 2;
		while (idx < n) {
			add = 3 - add;
			for (int i = 0; i < magic[idx] - '0'; i++) {
				magic += to_string(add);
			}
			idx++;
		}
		int answer = 0;
		for (int i = 0; i < n; i++) {
			if (magic[i] == '1') {
				answer++;
			}
		}
		return answer;
	}
};