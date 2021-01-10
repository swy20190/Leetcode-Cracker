#include <string>

using namespace std;

class Solution {
public:
	bool judgeCircle(string moves) {
		int vertical = 0;
		int horizontial = 0;
		for (char c : moves) {
			if (c == 'R') {
				horizontial++;
			}
			if (c == 'L') {
				horizontial--;
			}
			if (c == 'U') {
				vertical++;
			}
			if (c == 'D') {
				vertical--;
			}
		}
		return vertical == 0 && horizontial == 0;
	}
};