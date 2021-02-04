#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {
		int cont_0 = 0;
		int zero_max = -1;
		int len = seats.size();
		for (auto s : seats) {
			if (s == 0) {
				cont_0++;
			}
			else {
				zero_max = max(zero_max, cont_0);
				cont_0 = 0;
			}
		}
		int inner_min = (zero_max - 1) / 2;
		int head_zero = 0;
		if (seats[0] == 1) {
			head_zero = 0;
		}
		else {
			for (auto s : seats) {
				if (s == 0) {
					head_zero++;
				}
				else {
					break;
				}
			}
		}
		int tail_zero = 0;
		if (seats[len - 1] == 1) {
			tail_zero = 0;
		}
		else {
			for (int i = len - 1; i >= 0; i--) {
				if (seats[i] == 0) {
					tail_zero++;
				}
				else {
					break;
				}
			}
		}
		return max(inner_min, max(head_zero - 1, tail_zero - 1))+1;
	}
};

int main() {
	Solution solution;
	vector<int> seats = { 0, 0, 1 };
	cout << solution.maxDistToClosest(seats);
}