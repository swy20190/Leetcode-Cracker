#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int answer = 0;
		int len = startTime.size();
		for (int i = 0; i < len; i++) {
			if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
				answer++;
			}
		}
		return answer;
	}
};