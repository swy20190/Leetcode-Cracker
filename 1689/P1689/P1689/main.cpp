#include <string>

using namespace std;

class Solution {
public:
	int minPartitions(string n) {
		int answer = 0;
		for (auto c : n) {
			if (c - '0' > answer) {
				answer = c - '0';
			}
		}
		return answer;
	}
};