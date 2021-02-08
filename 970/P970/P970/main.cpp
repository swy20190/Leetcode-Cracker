#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<int> powerfulIntegers(int x, int y, int bound) {
		vector<int> answer;
		unordered_map<int, int> cnt_map;
		for (int i = 0; i <= 20; i++) {
			if (pow(x, i) > bound) {
				break;
			}
			for (int j = 0; j <= 20; j++) {
				int tmp = pow(x, i) + pow(y, j);
				if (tmp <= bound) {
					if (cnt_map[tmp] == 0) {
						answer.push_back(tmp);
						cnt_map[tmp]++;
					}
				}
				else {
					break;
				}
			}
		}
		return answer;
	}
};