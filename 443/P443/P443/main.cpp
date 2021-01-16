#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int compress(vector<char>& chars) {
		int slow = 0;
		int fast = 0;
		int curr_len = 1;
		for (fast; fast < chars.size(); fast++) {
			if (fast == chars.size() - 1 || chars[fast] != chars[fast + 1]) {
				chars[slow] = chars[fast];
				slow++;
				if (curr_len > 1) {
					for (char ch : to_string(curr_len)) {
						chars[slow] = ch;
						slow++;
					}
				}
				curr_len = 1;
			}
			else {
				curr_len++;
			}
		}
		return slow;
	}
};