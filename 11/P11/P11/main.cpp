#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {

		int maxVal = 0;
		int head = 0;
		int tail = height.size() - 1;
		while (head != tail) {
			if (height[head] < height[tail]) {
				int tmpVal = (tail - head) * height[head];
				if (tmpVal > maxVal) {
					maxVal = tmpVal;
				}
				head++;
			}
			else {
				int tmpVal = (tail - head) * height[tail];
				if (tmpVal > maxVal) {
					maxVal = tmpVal;
				}
				tail--;
			}
		}

		return maxVal;
	}
};

int main() {
	vector<int> height;
	height.push_back(1);
	height.push_back(8);
	height.push_back(6);
	height.push_back(2);
	height.push_back(5);
	height.push_back(4);
	height.push_back(8);
	height.push_back(3);
	height.push_back(7);
	Solution solution;
	cout << solution.maxArea(height);
}