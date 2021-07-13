#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<string> buildArray(vector<int>& target, int n) {
		vector<string> answer;
		int ptr = 1;
		for (int i = 0; i < target.size(); i++) {
			while (ptr < target[i]) {
				answer.push_back("Push");
				answer.push_back("Pop");
				ptr++;
			}
			if (ptr == target[i]) {
				answer.push_back("Push");
				ptr++;
			}
		}
		return answer;
	}
};