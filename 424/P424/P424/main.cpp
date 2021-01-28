#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int characterReplacement(string s, int k) {
		int* char_cnt = new int[26];
		for (int i = 0; i < 26; i++) {
			char_cnt[i] = 0;
		}
		int left = 0;
		int answer = 0;
		int max_cnt = 0;
		for (int right = 0; right < s.size(); right++) {
			char_cnt[s[right] - 'A']++;
			max_cnt = max(max_cnt, char_cnt[s[right] - 'A']);
			while (right - left + 1 - max_cnt > k) {
				char_cnt[s[left] - 'A']--;
				left++;
			}
			answer = max(answer, right - left + 1);
		}
		return answer;
	}
};