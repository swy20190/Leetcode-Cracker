#include <iostream>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);


class Solution {
public:
	int firstBadVersion(int n) {
		int left = 1;
		int right = n;
		while (true) {
			int mid = left + (right - left) / 2;
			bool flag = isBadVersion(mid);
			if (flag) {
				if (isBadVersion(mid - 1)) {
					right = mid;
				}
				else {
					return mid;
				}
			}
			else {
				left = mid + 1;
			}
		}
		return 0;
	}
};