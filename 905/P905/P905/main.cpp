#include <vector>

using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int> &nums) {
		vector<int> even_vec;
		vector<int> odd_vec;
		vector<int> answer;
		for (auto num : nums) {
			if (num % 2 == 0) {
				even_vec.push_back(num);
			}
			else {
				odd_vec.push_back(num);
			}
		}
		for (auto even : even_vec) {
			answer.push_back(even);
		}
		for (auto odd : odd_vec) {
			answer.push_back(odd);
		}
		return answer;
	}
};