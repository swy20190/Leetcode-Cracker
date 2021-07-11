#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end());
		int len = citations.size();
		for (int i = 0; i < len; i++) {
			if (citations[i] >= len - i) {
				return len - i;
			}
		}
		return 0;
	}
};