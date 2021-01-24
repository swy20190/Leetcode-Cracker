#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximumSwap(int num) {
		if (num == 0) {
			return 0;
		}
		string orig_num = to_string(num);
		string sort_num = orig_num;
		sort(sort_num.begin(), sort_num.end());
		reverse(sort_num.begin(), sort_num.end());
		if (orig_num == sort_num) {
			return num;
		}
		char smaller;
		char larger;
		for (int i = 0; i < orig_num.size(); i++) {
			if (orig_num[i] != sort_num[i]) {
				smaller = orig_num[i];
				larger = sort_num[i];
				orig_num[i] = sort_num[i];
				break;
			}
		}
		for (int i = orig_num.size() - 1; i >= 0; i--) {
			if (orig_num[i] == larger) {
				orig_num[i] = smaller;
				break;
			}
		}
		int answer = atoi(orig_num.c_str());
		return answer;
	}
};