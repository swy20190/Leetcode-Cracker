#include <vector>
#include <iostream>
#include <map>

using namespace std;


class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		map<int, int> ab_map;
		map<int, int> cd_map;
		for (auto& a : A) {
			for (auto& b : B) {
				++ab_map[a + b];
			}
		}
		for (auto& c : C) {
			for (auto& d : D) {
				++cd_map[c + d];
			}
		}
		int answer = 0;
		for (map<int, int>::iterator iter = ab_map.begin(); iter != ab_map.end(); iter++) {
			map<int, int>::iterator cd_iter = cd_map.find(iter->first*(-1));
			if (cd_iter != cd_map.end()) {
				answer += iter->second*cd_iter->second;
			}
		}
		return answer;
	}
};