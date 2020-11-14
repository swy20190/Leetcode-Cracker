#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
		vector<int> answer;
		int even_sum = 0;
		int len = A.size();
		for (int i = 0; i < len; i++) {
			if (A[i] % 2 == 0) {
				even_sum += A[i];
			}
		}
		int query_times = queries.size();
		for (int i = 0; i < query_times; i++) {
			int val = queries[i][0];
			int index = queries[i][1];
			int new_sum = even_sum;
			if (A[index] % 2 == 0) {
				if (val % 2 == 0) {
					new_sum += val;
				}
				else {
					new_sum -= A[index];
				}
			}
			else {
				if (val % 2 == 0) {

				}
				else {
					new_sum += val;
					new_sum += A[index];
				}
			}
			answer.push_back(new_sum);
			even_sum = new_sum;
			A[index] += val;
		}
		return answer;
	}
};