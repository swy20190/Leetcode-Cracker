#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
	bool isAnagram(string s, string t) {
		int s_count[26] = { 0 };
		int t_count[26] = { 0 };
		int s_len = s.size();
		int t_len = t.size();
		if (s_len != t_len) {
			return false;
		}
		for (int i = 0; i < s_len; i++) {
			s_count[s[i] - 'a']++;
		}
		for (int i = 0; i < t_len; i++) {
			t_count[t[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (s_count[i] != t_count[i]) {
				return false;
			}
		}
		return true;
	}
};