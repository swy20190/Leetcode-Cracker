#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<int> constructRectangle(int area) {
		vector<int> answer;
		int width = 0;
		for (int i = 1; i <= sqrt(area); i++) {
			if (area % i == 0) {
				width = i;
			}
		}
		int length = area / width;
		answer.push_back(length);
		answer.push_back(width);
		return answer;
	}
};