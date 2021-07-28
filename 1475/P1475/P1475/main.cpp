#include <vector>

using namespace std;

class Solution {
public:
	vector<int> finalPrices(vector<int>& prices) {
		vector<int> answer;
		int len = prices.size();
		for (int i = 0; i < len; i++) {
			int fact = 0;
			for (int j = i + 1; j < len; j++) {
				if (prices[j] <= prices[i]) {
					fact = prices[j];
					break;
				}
			}
			answer.push_back(prices[i] - fact);
		}
		return answer;
	}
};