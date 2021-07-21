#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> ans = { "Friday", "Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday" };
	vector<int> r = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	vector<int> p = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	inline bool isrun(int year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	string dayOfTheWeek(int day, int month, int year) {
		int days = 0, y;
		for (y = 1971; y < year; ++y) days += isrun(y) ? 366 : 365;
		if (isrun(y))for (int m = 1; m < month; ++m) days += r[m];
		else for (int m = 1; m < month; ++m) days += p[m];
		days += day - 1;
		return ans[days % 7];
	}
};