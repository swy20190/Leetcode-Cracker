#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		int answer = 0;
		int* hash = new int[100];
		for (int i = 0; i < 100; i++) {
			hash[i] = 0;
		}
		for (auto dom : dominoes) {
			sort(dom.begin(), dom.end());
			answer += hash[dom[0] * 10 + dom[1]];
			hash[dom[0] * 10 + dom[1]]++;
		}
		return answer;
	}
};