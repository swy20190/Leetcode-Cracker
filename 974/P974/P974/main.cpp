#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int subarraysDivByK(vector<int>& A, int K) {
		unordered_map<int, int> mod_hash;
		mod_hash[0] = 1;
		int curr_mod = 0;
		int answer = 0;
		for (auto a : A) {
			curr_mod = ((curr_mod + a) % K+K)%K;
			answer += mod_hash[curr_mod];
			mod_hash[curr_mod]++;
		}
		return answer;
	}
};