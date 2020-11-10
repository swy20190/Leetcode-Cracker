#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<char> q;
		int answer = 0;
		// int head = 0;
		int tail = 0;
		int len = s.length();
		if (len == 0) {
			return 0;
		}
		while (tail < len) {
			char tmp = s[tail];
			if (find(q.begin(), q.end(), tmp) == q.end()) {
				q.push_back(tmp);
				tail++;
				if (q.size() > answer) {
					answer = q.size();
				}
			}
			else {
				vector<char>::iterator iter = q.begin();
				while (iter != q.end()) {
					if (*iter == tmp) {
						break;
					}
					else {
						iter = q.erase(iter);
						// head++;
					}
				}
				iter = q.erase(iter);
				q.push_back(tmp);
				tail++;
				if (q.size() > answer) {
					answer = q.size();
				}
			}
		}
		return answer;
	}
};

int main() {
	string target = string("pwwkew");
	Solution solution;
	cout << solution.lengthOfLongestSubstring(target);
}