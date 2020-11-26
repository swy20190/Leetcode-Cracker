#include <iostream>

using namespace std;

class Solution {
public:
	bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
		if (x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2) {
			return true;
		}
		double d1 = euclid(x_center, y_center, x1, y1);
		double d2 = euclid(x_center, y_center, x1, y2);
		double d3 = euclid(x_center, y_center, x2, y1);
		double d4 = euclid(x_center, y_center, x2, y2);
		if (x_center < x1 && y_center < y1) {
			return radius >= d1;
		}
		if (x_center < x1 && y_center >= y1 && y_center <= y2) {
			return radius >= x1 - x_center;
		}
		if (x_center<x1&&y_center>y2) {
			return radius >= d2;
		}
		if (x_center >= x1 && x_center <= x2 && y_center > y2) {
			return radius >= y_center - y2;
		}
		if (x_center > x2 && y_center > y2) {
			return radius >= d4;
		}
		if (x_center > x2 && y_center <= y2 && y_center >= y1) {
			return radius >= x_center - x2;
		}
		if (x_center > x2 && y_center < y1) {
			return radius >= d3;
		}
		if (x_center >= x1 && x_center <= x2 && y_center < y1) {
			return radius >= y1 - y_center;
		}
	}

	double euclid(int x1, int y1, int x2, int y2) {
		return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	}
};