#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		string Ustr = "";
		int len = s.size();
		for (int i = 0; i < len; i++) {
			char tmp = s[i];
			if (tmp >= 'a' && tmp <= 'z') {
				Ustr += toupper(tmp);
			}
			else if ((tmp >= 'A' && tmp <= 'Z') || (tmp >= '0' && tmp <= '9')) {
				Ustr += tmp;
			}
		}
		int len_U = Ustr.size();
		for (int i = 0; i < len_U / 2; i++) {
			if (Ustr[i] != Ustr[len_U - 1 - i]) {
				return false;
			}
		}
		return true;
	}
};