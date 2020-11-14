#include <iostream>

using namespace std;

class Solution {
public:
	int brokenCalc(int X, int Y) {
		int step = 0;
		while (Y != X) {
			if (Y < X) {
				Y++;
			}
			else if (Y % 2 == 0) {
				Y /= 2;
			}
			else {
				Y++;
			}
			step++;
		}
		return step;
	}
};

int main() {
	Solution solution;
	cout << solution.brokenCalc(3, 10);
}