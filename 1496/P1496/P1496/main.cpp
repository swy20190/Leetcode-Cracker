#include <string>
#include <iostream>
#include <set>

using namespace std;

class Solution {
	set<int> route;
public:
	bool add(int x, int y) {
		int t = x * 1e5 + y;
		if (route.count(t) != 0) {
			return false;
		}
		route.insert(t);
		return true;
	}
	bool isPathCrossing(string path) {
		add(0, 0);
		int x = 0;
		int y = 0;
		for (auto p : path) {
			if (p == 'N') {
				y++;
			}
			else if (p == 'S') {
				y--;
			}
			else if (p == 'E') {
				x++;
			}
			else {
				x--;
			}
			if (!add(x, y)) {
				return true;
			}
		}
		return false;
	}
};