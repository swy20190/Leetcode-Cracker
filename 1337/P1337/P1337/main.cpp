#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		int n = mat.size();
		int m = mat[0].size();
		vector<int> answer;
		for (int i = 0; i < n; i++) {
			answer.push_back(i);
		}
		sort(answer.begin(), answer.end(), [&](const int& a, const int& b) {return mat[a] == mat[b] ? a < b : mat[a] < mat[b]; });
		vector<int> res(answer.begin(), answer.begin() + k);
		return res;
	}
};