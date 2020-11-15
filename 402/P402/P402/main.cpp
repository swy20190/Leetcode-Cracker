#include <string>
#include <iostream>


using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		if (num.length() == k) {
			return "0";
		}
		for (int i = 0; i < k; i++) {
			int index = 0;
			for (int j = 1; j < num.length() && num[j] >= num[j - 1]; j++) {
				index = j;
			}
			num.erase(num.begin() + index);
			while (num.length() > 1 && num[0] == '0') {
				num.erase(num.begin());
			}
		}
		return num;
	}
};

int main() {
	Solution solution;
	cout << solution.removeKdigits("1145141919810", 3);
}