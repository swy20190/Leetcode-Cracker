#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int len = citations.size();
		int left = 0;
		int right = len;
		while (left < right) {
			int mid = (left + right + 1) >> 1;
			if (citations[len - mid] >= mid) {
				left = mid;
			}
			else {
				right = mid - 1;
			}
		}
		return left;
	}
};