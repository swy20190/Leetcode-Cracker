#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
	string sortString(string s) {
		int cnts[26] = { 0 };
		int len = s.length();
		for (int i = 0; i < len; i++) {
			cnts[s[i] - 'a']++;
		}
		string answer;
		while (len > 0) {
			for (int i = 0; i < 26; i++) {
				if (cnts[i] > 0) {
					len--;
					cnts[i]--;
					answer = answer + char('a' + i);
				}
			}
			for (int i = 25; i >= 0; i--) {
				if (cnts[i] > 0) {
					len--;
					cnts[i]--;
					answer = answer + char('a' + i);
				}
			}
		}
		return answer;
	}
};