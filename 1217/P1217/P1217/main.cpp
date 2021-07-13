#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minCostToMoveChips(vector<int>& position) {
		int odd_cnt = 0;
		int even_cnt = 0;
		for (auto pos : position) {
			if (pos % 2 == 0) {
				even_cnt++;
			}
			else {
				odd_cnt++;
			}
		}
		return min(odd_cnt, even_cnt);
	}
};