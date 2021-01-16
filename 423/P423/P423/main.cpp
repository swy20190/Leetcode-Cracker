#include <string>

using namespace std;

class Solution {
public:
	string originalDigits(string s) {
		int n0 = cnt(s, 'z');
		int n2 = cnt(s, 'w');
		int n8 = cnt(s, 'g');
		int n6 = cnt(s, 'x');
		int n3 = cnt(s, 't') - n2 - n8;
		int n4 = cnt(s, 'r') - n3 - n0;
		int n7 = cnt(s, 's') - n6;
		int n1 = cnt(s, 'o') - n4 - n2 - n0;
		int n5 = cnt(s, 'v') - n7;
		int n9 = cnt(s, 'i') - n8 - n6 - n5;

		string answer = "";
		for (int i = 0; i < n0; i++) {
			answer = answer + "0";
		}
		for (int i = 0; i < n1; i++) {
			answer = answer + "1";
		}
		for (int i = 0; i < n2; i++) {
			answer = answer + "2";
		}
		for (int i = 0; i < n3; i++) {
			answer = answer + "3";
		}
		for (int i = 0; i < n4; i++) {
			answer = answer + "4";
		}
		for (int i = 0; i < n5; i++) {
			answer = answer + "5";
		}
		for (int i = 0; i < n6; i++) {
			answer = answer + "6";
		}
		for (int i = 0; i < n7; i++) {
			answer = answer + "7";
		}
		for (int i = 0; i < n8; i++) {
			answer = answer + "8";
		}
		for (int i = 0; i < n9; i++) {
			answer = answer + "9";
		}
		return answer;
	}

	int cnt(string& s, char ch) {
		int answer = 0;
		for (char c : s) {
			if (c == ch) {
				answer++;
			}
		}
		return answer;
	}
};