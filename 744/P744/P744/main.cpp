#include <vector>

using namespace std;

class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		int n = letters.size();
		int l = 0;
		int r = n;
		while (l < r) {
			int mid = l + r >> 1;
			if (letters[mid] > target) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		return l == n ? letters[0] : letters[l];
	}
};