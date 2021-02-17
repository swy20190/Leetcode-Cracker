#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> model;
		unordered_map<char, int> window;
		int left = 0;
		int right = 0;
		int start = 0;
		int len = INT_MAX;
		for (char c : t) {
			model[c]++;
		}
		int match = 0;
		while (right < s.size()) {
			char tmp = s[right];
			if (model.count(tmp) != 0) {
				window[tmp]++;
				if (window[tmp] == model[tmp]) {
					match++;
				}
			}
			right++;
			while (match == model.size()) {
				if (right - left < len) {
					len = right - left;
					start = left;
				}
				tmp = s[left];
				if (model.count(tmp) != 0) {
					window[tmp]--;
					if (window[tmp] < model[tmp]) {
						match--;
					}
				}
				left++;
			}
		}
		if (len == INT_MAX) {
			return "";
		}
		else {
			return s.substr(start, len);
		}
	}
};