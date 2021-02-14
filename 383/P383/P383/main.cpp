#include <string>

using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int bucket[26] = { 0 };
		for (char r : ransomNote) {
			bucket[r - 'a']++;
		}
		for (char m : magazine) {
			bucket[m - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (bucket[i] > 0) {
				return false;
			}
		}
		return true;
	}
};