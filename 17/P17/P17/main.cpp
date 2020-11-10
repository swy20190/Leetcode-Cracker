#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> answer;
		queue<string> tmpAnswer;
		if (digits.length() == 0) {
			return answer;
		}
		switch (digits[0]) {
		case '2':
			tmpAnswer.push("a");
			tmpAnswer.push("b");
			tmpAnswer.push("c");
			break;
		case '3':
			tmpAnswer.push("d");
			tmpAnswer.push("e");
			tmpAnswer.push("f");
			break;
		case '4':
			tmpAnswer.push("g");
			tmpAnswer.push("h");
			tmpAnswer.push("i");
			break;
		case '5':
			tmpAnswer.push("j");
			tmpAnswer.push("k");
			tmpAnswer.push("l");
			break;
		case '6':
			tmpAnswer.push("m");
			tmpAnswer.push("n");
			tmpAnswer.push("o");
			break;
		case '7':
			tmpAnswer.push("p");
			tmpAnswer.push("q");
			tmpAnswer.push("r");
			tmpAnswer.push("s");
			break;
		case '8':
			tmpAnswer.push("t");
			tmpAnswer.push("u");
			tmpAnswer.push("v");
			break;
		case '9':
			tmpAnswer.push("w");
			tmpAnswer.push("x");
			tmpAnswer.push("y");
			tmpAnswer.push("z");
			break;
		default:
			break;
		}
		if (digits.length() == 1) {
			while (!tmpAnswer.empty()) {
				answer.push_back(tmpAnswer.front());
				tmpAnswer.pop();
			}
			return answer;
		}
		int ptr = 1;
		int len = digits.length();
		while (ptr < len) {
			char currNum = digits[ptr];
			while (tmpAnswer.front().length() <= ptr) {
				string tmpStr = tmpAnswer.front();
				tmpAnswer.pop();
				switch (currNum) {
				case '2':
					tmpAnswer.push(tmpStr + "a");
					tmpAnswer.push(tmpStr + "b");
					tmpAnswer.push(tmpStr + "c");
					break;
				case '3':
					tmpAnswer.push(tmpStr + "d");
					tmpAnswer.push(tmpStr + "e");
					tmpAnswer.push(tmpStr + "f");
					break;
				case '4':
					tmpAnswer.push(tmpStr + "g");
					tmpAnswer.push(tmpStr + "h");
					tmpAnswer.push(tmpStr + "i");
					break;
				case '5':
					tmpAnswer.push(tmpStr + "j");
					tmpAnswer.push(tmpStr + "k");
					tmpAnswer.push(tmpStr + "l");
					break;
				case '6':
					tmpAnswer.push(tmpStr + "m");
					tmpAnswer.push(tmpStr + "n");
					tmpAnswer.push(tmpStr + "o");
					break;
				case '7':
					tmpAnswer.push(tmpStr + "p");
					tmpAnswer.push(tmpStr + "q");
					tmpAnswer.push(tmpStr + "r");
					tmpAnswer.push(tmpStr + "s");
					break;
				case '8':
					tmpAnswer.push(tmpStr + "t");
					tmpAnswer.push(tmpStr + "u");
					tmpAnswer.push(tmpStr + "v");
					break;
				case '9':
					tmpAnswer.push(tmpStr + "w");
					tmpAnswer.push(tmpStr + "x");
					tmpAnswer.push(tmpStr + "y");
					tmpAnswer.push(tmpStr + "z");
					break;
				default:
					break;
				}
			}
			ptr++;
		}
		while (!tmpAnswer.empty()) {
			answer.push_back(tmpAnswer.front());
			tmpAnswer.pop();
		}
		return answer;
	}
};

int main() {
	Solution solution;
	vector<string> answer = solution.letterCombinations("227");
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;
}