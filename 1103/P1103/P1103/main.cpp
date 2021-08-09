#include <vector>

using namespace std;

class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int> answer(num_people, 0);
		int cur = 0;
		while (candies > 0) {
			if (candies >= cur + 1) {
				answer[cur%num_people] += (cur + 1);
				candies = candies - cur - 1;
			}
			else {
				answer[cur%num_people] += candies;
				candies = 0;
			}
			cur++;
		}
		return answer;
	}
};