#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int maxCoins(vector<int>& piles) {
		sort(piles.begin(), piles.end());
		int len = piles.size();
		int answer = 0;
		for (int i = len / 3; i < len; i = i + 2) {
			answer += piles[i];
		}
		return answer;
	}
};