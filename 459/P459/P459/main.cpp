#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		string double_str = s + s;
		string mid_str = double_str.substr(1, double_str.size() - 2);
		string::size_type idx;
		idx = mid_str.find(s);
		if (idx == string::npos) {
			return false;
		}
		else {
			return true;
		}
	}
};