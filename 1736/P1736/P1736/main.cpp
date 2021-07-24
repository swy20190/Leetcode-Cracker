#include <string>

using namespace std;

class Solution {
public:
	string maximumTime(string time) {
		string answer = "";
		char h1 = time[0];
		char h2 = time[1];
		char m1 = time[3];
		char m2 = time[4];
		if (h1 == '?') {
			if (h2 == '?') {
				h1 = '2';
				h2 = '3';
			}
			else if (h2 == '0' || h2 == '1' || h2 == '2' || h2 == '3') {
				h1 = '2';
			}
			else {
				h1 = '1';
			}
		}
		else {
			if (h2 == '?') {
				if (h1 == '2') {
					h2 = '3';
				}
				else {
					h2 = '9';
				}
			}
		}
		if (m1 == '?') {
			m1 = '5';
		}
		if (m2 == '?') {
			m2 = '9';
		}
		answer = answer + h1;
		answer = answer + h2;
		answer = answer + ':';
		answer = answer + m1;
		answer = answer + m2;
		return answer;
	}
};