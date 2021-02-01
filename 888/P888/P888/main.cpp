#include <vector>

using namespace std;

class Solution {
public:
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		int sum_A = 0;
		int sum_B = 0;
		for (auto a : A) {
			sum_A += a;
		}
		for (auto b : B) {
			sum_B += b;
		}
		int diff = (sum_A - sum_B) / 2;
		for (auto a : A) {
			for (auto b : B) {
				if (a - b == diff) {
					return { a, b };
				}
			}
		}
		return { 0, 0 };
	}
};