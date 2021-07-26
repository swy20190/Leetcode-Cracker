#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		int char_map[26] = { 0 };
		int answer = 0;
		for (char c : chars) {
			char_map[c - 'a']++;
		}
		for (auto word : words) {
			bool available = true;
			int w_map[26] = { 0 };
			for (char w : word) {
				w_map[w - 'a']++;
			}
			for (int i = 0; i < 26; i++) {
				if (w_map[i] > char_map[i]) {
					available = false;
					break;
				}
			}
			if (available) {
				answer += word.size();
			}
		}
		return answer;
	}
};