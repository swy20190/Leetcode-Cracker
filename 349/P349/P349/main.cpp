#include <vector>
#include <set>

using namespace std;


class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> num_set1;
		set<int> intersect;
		vector<int> answer;
		for (int num : nums1) {
			num_set1.insert(num);
		}
		for (int num : nums2) {
			if (num_set1.count(num) > 0) {
				intersect.insert(num);
			}
		}
		for (int num : intersect) {
			answer.push_back(num);
		}
		return answer;
	}
};