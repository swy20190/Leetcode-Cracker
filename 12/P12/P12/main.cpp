#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
	string intToRoman(int num) {
		string answer;
		while (num >= 1000) {
			answer.append("M");
			num -= 1000;
		}
		if (num >= 900) {
			answer.append("CM");
			num -= 900;
		}
		else if (num >= 500) {
			answer.append("D");
			num -= 500;
			while (num >= 100) {
				answer.append("C");
				num -= 100;
			}
		}
		else if (num >= 400) {
			answer.append("CD");
			num -= 400;
		}
		else {
			while (num >= 100) {
				answer.append("C");
				num -= 100;
			}
		}

		if (num >= 90) {
			answer.append("XC");
			num -= 90;
		}
		else if (num >= 50) {
			answer.append("L");
			num -= 50;
			while (num >= 10) {
				answer.append("X");
				num -= 10;
			}
		}
		else if (num >= 40) {
			answer.append("XL");
			num -= 40;
		}
		else {
			while (num >= 10) {
				answer.append("X");
				num -= 10;
			}
		}

		if (num >= 9) {
			answer.append("IX");
			num -= 9;
		}
		else if (num >= 5) {
			answer.append("V");
			num -= 5;
			while (num >= 1) {
				answer.append("I");
				num -= 1;
			}
		}
		else if (num >= 4) {
			answer.append("IV");
			num -= 4;
		}
		else {
			while (num >= 1) {
				answer.append("I");
				num -= 1;
			}
		}
		return answer;
	}
};

int main() {
	Solution solution;
	cout << solution.intToRoman(1994) << endl;
}