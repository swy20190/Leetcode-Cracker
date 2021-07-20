#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string generateTheString(int n) {
		if (n % 2 == 0) {
			string answer(n-1, 'a');
			answer = answer + 'b';
			return answer;
		}
		else {
			string answer(n, 'a');
			return answer;
		}
	}
};