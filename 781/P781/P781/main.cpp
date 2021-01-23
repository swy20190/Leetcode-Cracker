#include <vector>

using namespace std;

class Solution {
public:
	int numRabbits(vector<int>& answers) {
		int hash[1005] = {0};
		for (auto ans : answers) {
			hash[ans]++;
		}
		int answer = 0;
		for (int i = 0; i < 1005; i++) {
			if (hash[i] != 0) {
				if (hash[i] % (i + 1) == 0) {
					answer = answer + hash[i];
				}
				else {
					answer = answer + (i + 1)*(hash[i] / (i + 1) + 1);
				}
			}
		}
		return answer;
	}
};