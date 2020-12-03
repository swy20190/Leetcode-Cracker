#include <vector>
#include <ctime>


#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Solution {
	double r;
	double x_c;
	double y_c;
public:
	Solution(double radius, double x_center, double y_center) {
		r = radius;
		x_c = x_center;
		y_c = y_center;
	}

	vector<double> randPoint() {
		vector<double> answer;
		// srand((int)time(0));
		double rand_r = sqrt((rand()/double(RAND_MAX))*r*r);
		double rand_angle = rand() / double(RAND_MAX) * 2 * M_PI;
		double rand_x = x_c + rand_r * cos(rand_angle);
		double rand_y = y_c + rand_r * sin(rand_angle);
		answer.push_back(rand_x);
		answer.push_back(rand_y);
		return answer;
	}
};