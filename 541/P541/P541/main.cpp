#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		for (int i = 0; i < s.size();) {
			int j = i;
			while (j < s.size() && j < i + k * 2) {
				j++;
			}
			reverse(s.begin() + i, s.begin() + min(k + i, j));
			i = j;
		}
		return s;
	}
};