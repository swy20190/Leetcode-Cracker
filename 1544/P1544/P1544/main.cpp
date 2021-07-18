#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string makeGood(string s) {
		vector<char> ss;
		int len = s.size();
		for (int i = 0; i < len; i++) {
			if (ss.size() == 0) {
				ss.push_back(s[i]);
			}
			else {
				char tail = ss[ss.size() - 1];
				if (tail >= 'A' && tail <= 'Z') {
					if (s[i] - tail != 32) {
						ss.push_back(s[i]);
					}
					else {
						ss.pop_back();
					}
				}
				else {
					if (tail - s[i] != 32) {
						ss.push_back(s[i]);
					}
					else {
						ss.pop_back();
					}
				}
			}
		}
		string answer = "";
		for (auto c : ss) {
			answer = answer + c;
		}
		return answer;
	}
};