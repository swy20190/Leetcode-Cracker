#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size()) {
			return false;
		}
		vector<int> mode(26, 0);
		vector<int> window(26, 0);
		for (int i = 0; i < s1.size(); i++) {
			mode[s1[i] - 'a']++;
		}
		int left = 0;
		int right = s1.size();
		for (int i = 0; i < s1.size(); i++) {
			window[s2[i] - 'a']++;
		}
		if (window == mode) {
			return true;
		}
		while (right < s2.size()) {
			window[s2[right] - 'a']++;
			window[s2[left] - 'a']--;
			if (window == mode) {
				return true;
			}
			right++;
			left++;
		}
		return false;
	}
};