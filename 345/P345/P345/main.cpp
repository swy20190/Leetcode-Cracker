#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		int left = 0;
		int right = s.size() - 1;
		while (left < right) {
			char tmp_l = s[left];
			if (tmp_l == 'a' || tmp_l == 'e' || tmp_l == 'i' || tmp_l == 'o' || tmp_l == 'u' || tmp_l == 'A' || tmp_l == 'E' || tmp_l == 'I' || tmp_l == 'O' || tmp_l == 'U') {
				char tmp_r = s[right];
				while (left < right && !(tmp_r == 'a' || tmp_r == 'e' || tmp_r == 'i' || tmp_r == 'o' || tmp_r == 'u' || tmp_r == 'A' || tmp_r == 'E' || tmp_r == 'I' || tmp_r == 'O' || tmp_r == 'U')) {
					right--;
					tmp_r = s[right];
				}
				swap(s[left], s[right]);
				right--;
			}
			left++;
		}
		return s;
	}
};