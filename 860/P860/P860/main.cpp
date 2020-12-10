#include <vector>

using namespace std;


class Solution {
public:
	bool lemonadeChange(vector<int>& bills) {
		int fiveCnt = 0;
		int tenCnt = 0;
		if (bills.size() == 0) {
			return true;
		}
		for (int bill : bills) {
			if (bill == 5) {
				fiveCnt++;
			}
			else if (bill == 10) {
				fiveCnt--;
				tenCnt++;
			}
			else {
				if (tenCnt > 0) {
					tenCnt--;
					fiveCnt--;
				}
				else {
					fiveCnt -= 3;
				}
			}
			if (fiveCnt < 0) {
				return false;
			}
		}
		return true;
	}
};