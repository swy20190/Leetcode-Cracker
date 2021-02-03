#include <string>

using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		int len_s = s.size();
		int len_t = t.size();
		if (len_s > len_t) {
			return false;
		}
		int ptr_s = 0;
		int ptr_t = 0;
		while (ptr_s < len_s) {
			while (ptr_t < len_t && t[ptr_t] != s[ptr_s]) {
				ptr_t++;
			}
			if (ptr_t == len_t) {
				return false;
			}
			else {
				ptr_t++;
				ptr_s++;
			}
		}
		return true;
	}
};