#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double average(vector<int>& salary) {
		if (salary.size() <= 2) {
			return 0;
		}
		int sum = 0;
		sort(salary.begin(), salary.end());
		for (int i = 1; i < salary.size() - 1; i++) {
			sum += salary[i];
		}
		return sum / (double)(salary.size() - 2);
	}
};