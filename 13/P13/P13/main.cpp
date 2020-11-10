#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int answer = 0;
		int ptr = 0;
		int len = s.length();
		while (ptr < len) {
			char tmp = s[ptr];
			switch (tmp) {
			case 'M':
				answer += 1000;
				ptr++;
				break;
			case  'D':
				answer += 500;
				ptr++;
				break;
			case 'C':
				if (ptr == len - 1) {
					answer += 100;
					ptr++;
				}
				else {
					if (s[ptr + 1] == 'M') {
						answer += 900;
						ptr += 2;
					}
					else if (s[ptr + 1] == 'D') {
						answer += 400;
						ptr += 2;
					}
					else {
						answer += 100;
						ptr++;
					}
				}
				break;
			case 'L':
				answer += 50;
				ptr++;
				break;
			case 'X':
				if (ptr == len - 1) {
					answer += 10;
					ptr++;
				}
				else {
					if (s[ptr + 1] == 'C') {
						answer += 90;
						ptr += 2;
					}
					else if (s[ptr + 1] == 'L') {
						answer += 40;
						ptr += 2;
					}
					else {
						answer += 10;
						ptr++;
					}
				}
				break;
			case 'V':
				answer += 5;
				ptr++;
				break;
			case 'I':
				if (ptr == len - 1) {
					answer += 1;
					ptr++;
				}
				else {
					if (s[ptr + 1] == 'X') {
						answer += 9;
						ptr += 2;
					}
					else if (s[ptr + 1] == 'V') {
						answer += 4;
						ptr += 2;
					}
					else {
						answer += 1;
						ptr++;
					}
				}
				break;
			default:
				break;
			}
		}
		return answer;
	}
};

int main() {
	Solution solution;
	cout << solution.romanToInt("MCMXCIV") << endl;
}