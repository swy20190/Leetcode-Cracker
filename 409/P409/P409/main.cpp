#include <string>

using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		int* cnt = new int[128];
		for (int i = 0; i < 128; i++) {
			cnt[i] = 0;
		}
		for (char c : s) {
			cnt[c - 'A']++;
		}
		bool has_center = false;
		int answer = 0;
		for (int i = 0; i < 128; i++) {
			if (cnt[i] % 2 == 0) {
				answer += cnt[i];
			}
			else {
				answer += (cnt[i] - 1);
				has_center = true;
			}
		}
		if (has_center) {
			answer++;
		}
		return answer;
	}
};