#include <vector>

using namespace std;

class Solution {
public:
	bool checkIfExist(vector<int>& arr) {
		int size = arr.size();
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (arr[i] == arr[j] * 2 || arr[i] * 2 == arr[j]) {
					return true;
				}
			}
		}
		return false;
	}
};