#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minSteps(int n) {
		if (n == 1) {
			return 0;
		}
		vector<int> factors;
		while (n != 1) {
			for (int i = 2; i <= n; i++) {
				if (n%i == 0) {
					n = n / i;
					factors.push_back(i);
					break;
				}
			}
		}
		int answer = 0;
		int len = factors.size();
		for (int i = 0; i < len; i++) {
			answer += factors[i];
		}
		return answer;
	}
};

int main() {
	Solution solution;
	cout << solution.minSteps(27);
}