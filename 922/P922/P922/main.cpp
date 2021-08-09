#include <vector>

using namespace std;

class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		vector<int> odd_vec;
		vector<int> even_vec;
		vector<int> answer;
		for (int a : A) {
			if (a % 2 == 0) {
				even_vec.push_back(a);
			}
			else {
				odd_vec.push_back(a);
			}
		}
		for (int i = 0; i < odd_vec.size(); i++) {
			answer.push_back(even_vec[i]);
			answer.push_back(odd_vec[i]);
		}
		return answer;
	}
};