#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.size();
		int answer = 0;
		int tail;
		for (int i = len - 1; i >= 0; i--) {
			if (s.at(i) != ' ') {
				tail = i;
				break;
			}
		}
		for (int i = tail; i >= 0; i--) {
			if (s.at(i) != ' ') {
				answer++;
			}
			else {
				break;
			}
		}
		return answer;
	}
};