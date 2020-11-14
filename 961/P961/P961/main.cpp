#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		int num_count[10000] = { 0 };
		int len = A.size();
		int answer = 0;
		for (int i = 0; i < len; i++) {
			int tmp = A[i];
			if (num_count[tmp] == 0) {
				num_count[tmp]++;
			}
			else {
				answer = tmp;
				break;
			}
		}
		return answer;
	}
};

int main() {
	vector<int> A = { 5, 1, 5, 2, 5, 3, 5, 4 };
	Solution solution;
	cout << solution.repeatedNTimes(A);
}