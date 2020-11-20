#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string toLowerCase(string str) {
		string ans;
		int len = str.length();
		for (int i = 0; i < len; i++) {
			if (str[i] >= 'A'&&str[i] <= 'Z') {
				char tmp = str[i] + 32;
				ans = ans + tmp;
			}
			else {
				ans = ans + str[i];
			}
		}
		return ans;
	}
};

int main() {
	Solution solution;
	cout << solution.toLowerCase("ebhuqAUBDYEBvf");
}