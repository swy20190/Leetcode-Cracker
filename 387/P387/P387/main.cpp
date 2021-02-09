#include <string>

using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		int hash[26] = { 0 };
		int len = s.size();
		for (int i = 0; i < len; i++) {
			hash[s[i] - 'a']++;
		}
		for (int i = 0; i < len; i++) {
			if (hash[s[i] - 'a'] == 1) {
				return i;
			}
		}
		return -1;
	}
};