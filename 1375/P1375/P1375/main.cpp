#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int numTimesAllBlue(vector<int>& light) {
		int len = light.size();
		int cnt = 0;
		int maxOnIndex = 0;
		for (int i = 0; i < len; i++) {
			maxOnIndex = max(maxOnIndex, light[i]);
			if (i == maxOnIndex - 1) {
				cnt++;
			}
		}
		return cnt;
	}
};