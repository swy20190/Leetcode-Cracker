#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int countStudents(vector<int>& students, vector<int>& sandwiches) {
		int student_0 = 0;
		int student_1 = 0;
		for (auto s : students) {
			if (s == 0) {
				student_0++;
			}
			else {
				student_1++;
			}
		}
		int sand_0 = 0;
		int sand_1 = 1;
		for (auto sand : sandwiches) {
			if (sand == 0) {
				if (student_0 == 0) {
					break;
				}
				else {
					student_0--;
				}
			}
			else {
				if (student_1 == 0) {
					break;
				}
				else {
					student_1--;
				}
			}
		}
		return student_0 + student_1;
	}
};
