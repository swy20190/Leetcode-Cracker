#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<char> digits = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		const int facs[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 352880 };
		string answer;
		for (--k; n--; k %= facs[n]) {
			const int i = k / facs[n];
			answer.push_back(digits[i]);
			digits.erase(digits.begin() + i);
		}
		return answer;
	}
};