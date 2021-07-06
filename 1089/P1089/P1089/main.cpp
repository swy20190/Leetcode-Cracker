#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		int i = 0;
		int tail = 0;
		int len = arr.size();
		for (i = 0; i < len; i++) {
			tail++;
			if (arr[i] == 0) {
				tail++;
			}
			if (tail >= len) {
				break;
			}
		}
		for (int j = len - 1; j >= 0; j--) {
			if (arr[i] != 0) {
				arr[j] = arr[i];
			}
			else if (arr[i] == 0 && tail > len && j == len - 1) {
				arr[j] = arr[i];
			}
			else {
				arr[j] = arr[i];
				arr[j - 1] = arr[i];
				j--;
			}
			i--;
		}
	}
};