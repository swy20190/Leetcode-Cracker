#include <vector>

using namespace std;

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> answer;
		for (int num1 : nums1) {
			bool find_bigger = false;
			bool find = false;
			for (int num2 : nums2) {
				if (num2 == num1) {
					find = true;
				}
				if (num2 > num1 && find) {
					answer.push_back(num2);
					find_bigger = true;
					break;
				}
			}
			if (!find_bigger) {
				answer.push_back(-1);
			}
		}
		return answer;
	}
};