#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		int num = K - (S.size() - count(S.begin(), S.end(), '-')) % K;
		string rst = "";
		for (auto c : S) {
			if (c == '-') {
				continue;
			}
			if (num == 0 && rst != "") {
				rst += '-';
			}
			rst += toupper(c);
			num = (num + 1) % K;
		}
		return rst;
	}
};