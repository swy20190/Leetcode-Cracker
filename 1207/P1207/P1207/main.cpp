#include <vector>

using namespace std;

class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		int bucket[2005] = { 0 };
		for (auto num : arr) {
			bucket[num + 1000] ++;
		}
		int cnt_bucket[1001] = { 0 };
		for (int i = 0; i < 2005; i++) {
			cnt_bucket[bucket[i]]++;
		}
		for (int i = 1; i < 1001; i++) {
			if (cnt_bucket[i] > 1) {
				return false;
			}
		}
		return true;
	}
};