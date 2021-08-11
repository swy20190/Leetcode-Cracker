#include <string>

using namespace std;

class Solution {
public:
	bool checkIfPangram(string sentence) {
		int bucket[26] = { 0 };
		for (auto c : sentence) {
			bucket[c - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (bucket[i] == 0) {
				return false;
			}
		}
		return true;
	}
};