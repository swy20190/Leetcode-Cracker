#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {
		int bucket[52] = { 0 };
		int num_j = jewels.size();
		int num_s = stones.size();
		for (int i = 0; i < num_s; i++) {
			if (stones[i] >= 'a') {
				bucket[stones[i] - 71]++;
			}
			else
				bucket[stones[i] - 'A']++;
		}
		int answer = 0;
		for (int i = 0; i < num_j; i++) {
			if (jewels[i] >= 'a') {
				answer += bucket[jewels[i] - 71];
			}
			else
				answer += bucket[jewels[i] - 'A'];
		}
		return answer;
	}
};