#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> numMovesStones(int a, int b, int c) {
		vector<int> answer;
		vector<int> stones;
		stones.push_back(a);
		stones.push_back(b);
		stones.push_back(c);
		sort(stones.begin(), stones.end());
		if (stones[0] == stones[1] - 1 && stones[1] == stones[2] - 1) {
			answer.push_back(0);
		}
		else if (stones[0] == stones[1] - 2 ||stones[1] == stones[2]-2 || stones[0]==stones[1]-1 || stones[1]==stones[2]-1) {
			answer.push_back(1);
		}
		else {
			answer.push_back(2);
		}
		answer.push_back(stones[2] - stones[0] - 2);
		return answer;
	}
};