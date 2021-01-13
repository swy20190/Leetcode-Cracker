#include <string>
#include <algorithm> 

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int ptr1 = a.size() - 1;
		int ptr2 = b.size() - 1;
		string answer = "";
		int carry = 0;
		while (ptr1 >= 0 || ptr2 >= 0) {
			if (ptr1 >= 0) {
				carry += a[ptr1] - '0';
				ptr1--;
			}
			if (ptr2 >= 0) {
				carry += b[ptr2] - '0';
				ptr2--;
			}
			
			answer = answer + to_string(carry%2);
			carry = carry / 2;
		}
		if (carry == 1) {
			answer = answer + to_string(carry);
		}
		reverse(answer.begin(), answer.end());
		return answer;
	}
};