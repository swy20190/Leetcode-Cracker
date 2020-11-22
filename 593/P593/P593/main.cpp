#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		if ((p1[0] == p2[0] && p1[1] == p2[1])||(p1[0]==p3[0]&&p1[1]==p3[1])||(p1[0]==p4[0]&&p1[1]==p4[1])||(p2[0]==p3[0]&&p2[1]==p3[1])
			||(p2[0]==p4[0]&&p2[1]==p4[1])||(p3[0]==p4[0]&&p3[1]==p4[1])) {
			return false;
		}
		vector<double> sides;
		sides.push_back(length(p1, p2));
		sides.push_back(length(p1, p3));
		sides.push_back(length(p1, p4));
		sides.push_back(length(p2, p3));
		sides.push_back(length(p2, p4));
		sides.push_back(length(p3, p4));
		int count_1 = 0;
		int count_2 = 0;
		double another_side = -1.0;
		for (int i = 0; i < 6; i++) {
			if (sides[i] == length(p1, p2)) {
				count_1++;
			}
			else {
				if (another_side == -1.0) {
					another_side = sides[i];
					count_2++;
				}
				else {
					if (another_side == sides[i]) {
						count_2++;
					}
				}
			}
		}
		return (count_1 == 4 && count_2 == 2) || (count_1 == 2 && count_2 == 4);
	}

	double length(vector<int> pp, vector<int> ppp) {
		return sqrt((pp[0] - ppp[0])*(pp[0] - ppp[0]) + (pp[1] - ppp[1])*(pp[1] - ppp[1]));
	}
};