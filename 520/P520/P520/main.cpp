#include <string>

using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		int lastUpperIndex = -1;
		int lastLowerIndex = -1;
		for (int i = 0; i < word.size(); i++) {
			if (word.at(i) >= 'a' && word.at(i) <= 'z') {
				lastLowerIndex = i;
			}
			else {
				lastUpperIndex = i;
			}
		}
		if (lastUpperIndex > 0 && lastLowerIndex >= 0) {
			return false;
		}
		return true;
	}
};