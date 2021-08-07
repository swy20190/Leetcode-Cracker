#include <string>

using namespace std;

class Solution {
public:
	string convertToTitle(int columnNumber) {
		if (columnNumber <= 0){
			return "";
		}
		string answer = "";
		while (columnNumber > 0) {
			columnNumber--;
			answer += (char)(columnNumber % 26 + 'A');
			columnNumber = columnNumber / 26;
		}
		reverse(answer.begin(), answer.end());
		return answer;
	}
};