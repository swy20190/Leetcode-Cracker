#include <iostream>

using namespace std;

class Solution {
public:
	int addDigits(int num) {
		if (num <= 9) {
			return num;
		}
		else {
			num = num % 9;
			if (num == 0) {
				return 9;
			}
			else {
				return num;
			}
		}
	}
};