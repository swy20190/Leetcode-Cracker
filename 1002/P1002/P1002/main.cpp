#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> commonChars(vector<string>& words) {
		vector<vector<int>> bucket(26);
		for (auto word : words) {
			int str_bucket[26] = { 0 };
			int str_len = word.size();
			for (int i = 0; i < str_len; i++) {
				str_bucket[word[i] - 'a']++;
			}
			for (int i = 0; i < 26; i++) {
				bucket[i].push_back(str_bucket[i]);
			}
		}
		vector<string> answer;
		for (int i = 0; i < 26; i++) {
			char tmp_char = 'a' + i;
			string tmp_str(1, tmp_char);
			int repeat = *min_element(bucket[i].begin(), bucket[i].end());
			for (int j = 0; j < repeat; j++) {
				answer.push_back(tmp_str);
			}
		}
		return answer;
	}
};