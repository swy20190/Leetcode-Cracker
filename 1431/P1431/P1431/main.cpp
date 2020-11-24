#include <vector>

using namespace std;

class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		int max = INT_MIN;
		for (auto candy : candies) {
			if (candy > max) {
				max = candy;
			}
		}
		vector<bool> answer;
		for (auto candy : candies) {
			if (candy + extraCandies >= max) {
				answer.push_back(true);
			}
			else {
				answer.push_back(false);
			}
		}
		return answer;
	}
};