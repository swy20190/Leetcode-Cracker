#include <vector>

using namespace std;

class Solution {
public:
	int numPairsDivisibleBy60(vector<int>& time) {
		int len = time.size();
		if (len < 2) {
			return 0;
		}
		int answer = 0;
		int* mod_hash = new int[60];
		for (int i = 0; i < 60; i++) {
			mod_hash[i] = 0;
		}
		for (auto t : time) {
			t = t % 60;
			if (t == 0) {
				answer += mod_hash[0];
			}
			else {
				answer += mod_hash[60 - t];
			}
			mod_hash[t] ++;
		}
		return answer;
	}
};