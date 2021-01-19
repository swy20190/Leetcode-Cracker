#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> answer;
		string line1 = "qwertyuiopQWERTYUIOP";
		string line2 = "asdfghjklASDFGHJKL";
		string line3 = "zxcvbnmZXCVBNM";
		for (int i = 0; i < words.size(); i++) {
			int n1 = 0;
			int n2 = 0;
			int n3 = 0;
			int len = words[i].size();
			for (int j = 0; j < len; j++) {
				if (line1.find(words[i][j]) != string::npos) {
					n1++;
				}
				else if (line2.find(words[i][j]) != string::npos) {
					n2++;
				}
				else if (line3.find(words[i][j]) != string::npos) {
					n3++;
				}
			}
			if (n1 == len || n2 == len || n3 == len) {
				answer.push_back(words[i]);
			}
		}
		return answer;
	}
};