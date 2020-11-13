#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int* ptrs = new int[n];
		for (int i = 0; i < n; i++) {
			ptrs[i] = 0;
		}
		int answer = 0;
		for (int i = 0; i < k; i++) {
			int min = INT_MAX;
			int min_index = -1;
			for (int j = 0; j < n; j++) {
				if (ptrs[j] == -1) {
					continue;
				}
				if (matrix[j][ptrs[j]] < min) {
					min = matrix[j][ptrs[j]];
					min_index = j;
				}
			}
			answer = min;
			if (ptrs[min_index] == n - 1) {
				ptrs[min_index] = -1;
			}
			else {
				ptrs[min_index] ++;
			}
		}
		return answer;
	}
};