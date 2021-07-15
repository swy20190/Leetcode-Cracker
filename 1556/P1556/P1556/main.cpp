#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string thousandSeparator(int n) {
		string s = to_string(n);
		int len = s.size();
		while (len) {
			len -= 3;
			if (len <= 0) {
				break;
			}
			s.insert(len, ".");
		}
		return s;
	}
};