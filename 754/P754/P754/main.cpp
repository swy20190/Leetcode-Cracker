#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int reachNumber(int target) {
		int answer = 1;
		int sum = 0;
		if (target == 0) {
			return 0;
		}
		target = abs(target);
		while (true) {
			sum += answer;
			if (sum == target || (sum > target && (sum - target) % 2 == 0)) {
				return answer;
			}
			answer++;
		}
	}
};