#include <string>

using namespace std;

class Solution {
public:
	int countSegments(string s) {
		string ss = s + " ";
		int answer = 0;
		for (int i = 0; i < s.size(); i++) {
			if (ss[i] != ' ' && ss[i + 1] == ' ') {
				answer++;
			}
		}
		return answer;
	}
};