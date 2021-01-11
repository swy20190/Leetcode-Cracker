#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		string answer = "";
		int carry = 0;
		int tail1 = num1.size() - 1;
		int tail2 = num2.size() - 1;
		while (tail1 >= 0 || tail2 >= 0) {
			if (tail1 >= 0) {
				carry += num1[tail1] - '0';
				tail1--;
			}
			if (tail2 >= 0) {
				carry += num2[tail2] - '0';
				tail2--;
			}
			answer = answer + to_string(carry % 10);
			carry = carry / 10;
		}
		if (carry != 0) {
			answer = answer + to_string(carry);
		}
		reverse(answer.begin(), answer.end());
		return answer;
	}
};