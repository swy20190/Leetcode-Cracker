#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxIceCream(vector<int>& costs, int coins) {
		int answer = 0;
		sort(costs.begin(), costs.end());
		if (costs.empty()) {
			return 0;
		}
		if (costs[0] > coins) {
			return 0;
		}
		for (int i = 0; i < costs.size(); i++) {
			if (costs[i] <= coins) {
				answer++;
				coins = coins - costs[i];
			}
			else {
				break;
			}
		}
		return answer;
	}
};