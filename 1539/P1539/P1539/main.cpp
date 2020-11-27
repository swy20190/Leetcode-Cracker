#include <vector>

using namespace std;

class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		int len = arr.size();
		if (len == 0) {
			return k;
		}
		int index = len-1;
		if (arr[index] - len < k) {
			return k + len;
		}
		for (int i = 0; i < len; i++) {
			if (arr[i] - i - 1 >= k) {
				index = i;
				break;
			}
		}
		index--;
		return k + index + 1;
	}
};