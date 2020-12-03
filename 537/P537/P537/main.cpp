#include <string>

using namespace std;

class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		int a1 = 0;
		int a2 = 0;
		int b1 = 0;
		int b2 = 0;
		sscanf(a.c_str(), "%d+%di", &a1, &a2);
		sscanf(b.c_str(), "%d+%di", &b1, &b2);
		string answer = to_string(a1*b1 - a2 * b2) + "+" + to_string(a1*b2 + a2 * b1) + "i";
		return answer;
	}
};