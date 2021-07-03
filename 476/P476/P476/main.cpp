#include <iostream>

using namespace std;

class Solution {
public:
	int findComplement(int num) {
		int answer = 0;
		int k = num;
		while (k) {
			k = k >> 1;
			answer = answer * 2 + 1;
		}
		return answer ^ num;
	}
};