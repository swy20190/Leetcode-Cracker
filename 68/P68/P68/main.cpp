#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> answer;
		for (int i = 0; i < words.size(); i++) {
			int j = i + 1;
			int len = words[i].size();
			while (j < words.size() && len + 1 + words[j].size() <= maxWidth) {
				len += 1 + words[j].size();
				j++;
			}
			string line;
			if (j == words.size() || j == i + 1) {
				line += words[i];
				for (int k = i + 1; k < j; k++) {
					line += ' ' + words[k];
				}
				while (line.size() < maxWidth) {
					line += ' ';
				}
			}
			else {
				int cnt = j - i - 1;
				int r = maxWidth - len + cnt;
				line += words[i];
				int a = r / cnt;
				int b = r % cnt;
				for (int k = i + 1; k < j; k++) {
					if (b-- > 0) {
						line += string(a + 1, ' ') + words[k];
					}
					else {
						line += string(a, ' ') + words[k];
					}
				}
			}
			answer.push_back(line);
			i = j - 1;
		}
		return answer;
	}
};