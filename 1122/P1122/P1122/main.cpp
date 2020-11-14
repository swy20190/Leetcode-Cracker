#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		int* count = new int[1001];
		for (int i = 0; i < 1001; i++) {
			count[i] = 0;
		}
		int arr1_len = arr1.size();
		int arr2_len = arr2.size();
		for (int i = 0; i < arr1_len; i++) {
			count[arr1[i]]++;
		}
		vector<int> answer;
		for (int i = 0; i < arr2_len; i++) {
			int tmp_count = count[arr2[i]];
			for (int j = 0; j < tmp_count; j++) {
				answer.push_back(arr2[i]);
			}
			count[arr2[i]] = 0;
		}
		for (int i = 0; i < 1001; i++) {
			int tmp_count = count[i];
			for (int j = 0; j < tmp_count; j++) {
				answer.push_back(i);
			}
		}
		return answer;
	}
};


int main() {
	vector<int> arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
	vector<int> arr2 = { 2,1,4,3,9,6 };
	Solution solution;
	vector<int> answer = solution.relativeSortArray(arr1, arr2);
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}