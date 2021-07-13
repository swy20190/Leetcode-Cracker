#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int maxNumberOfBalloons(string text) {
		int cnt_b = 0, cnt_a = 0, cnt_l = 0, cnt_o = 0, cnt_n = 0;
		int len = text.size();
		for (int i = 0; i < len; i++) {
			char tmp = text[i];
			switch (tmp)
			{
			case 'b':
				cnt_b++;
				break;
			case 'a':
				cnt_a++;
				break;
			case 'l':
				cnt_l++;
				break;
			case 'o':
				cnt_o++;
				break;
			case 'n':
				cnt_n++;
				break;
			default:
				break;
			}
		}
		int answer = INT_MAX;
		if (cnt_b < answer) {
			answer = cnt_b;
		}
		if (cnt_a < answer) {
			answer = cnt_a;
		}
		if (cnt_l < answer * 2) {
			answer = cnt_l / 2;
		}
		if (cnt_o < answer * 2) {
			answer = cnt_o / 2;
		}
		if (cnt_n < answer) {
			answer = cnt_n;
		}
		return answer;
	}
};