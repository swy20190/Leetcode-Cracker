#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int start = 0;
		int len = gas.size();
		bool canComplete = false;
		while (start < len) {
			if (gas[start] >= cost[start]) {
				int diff = gas[start] - cost[start];
				bool success = true;
				for (int i = 0; i < len; i++) {
					int index = (start + i + 1) % len;
					diff = diff + gas[index] - cost[index];
					if (diff < 0) {
						start = start + i + 1;
						success = false;
						break;
					}
				}
				if (success) {
					canComplete = true;
					break;
				}
			}
			else {
				start++;
			}
		}
		if (canComplete) {
			return start;
		}
		else {
			return -1;
		}
	}
};

int main() {
	vector<int> gas = { 3, 3, 4 };
	vector<int> cost = { 3, 4, 4 };
	Solution solution;
	cout << solution.canCompleteCircuit(gas, cost);
}