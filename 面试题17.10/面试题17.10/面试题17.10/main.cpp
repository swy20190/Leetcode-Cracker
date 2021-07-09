#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int boss = -1;
		int count = 0;
		for (auto num : nums) {
			if (num == boss) {
				count++;
			}
			else {
				if (count > 0) {
					count--;
				}
				else {
					boss = num;
					count = 1;
				}
			}
		}
		int boss_cnt = 0;
		for (auto num : nums) {
			if (num == boss) {
				boss_cnt++;
			}
		}
		if (boss_cnt > nums.size() / 2) {
			return boss;
		}
		else {
			return -1;
		}
	}
};