#include <iostream>

using namespace std;


class Solution {
public:
	double angleClock(int hour, int minutes) {
		double minute_angle = 6.0*minutes;
		double hour_angle = 30.0*(hour % 12) + minutes / 60.0*30.0;
		double diff = abs(hour_angle - minute_angle);
		if (diff > 180) {
			diff = 360.0 - diff;
		}
		return diff;
	}
};