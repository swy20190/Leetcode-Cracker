#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
		unordered_map<int, vector<int>> mp;
		for (auto& adPair : adjacentPairs) {
			mp[adPair[0]].push_back(adPair[1]);
			mp[adPair[1]].push_back(adPair[0]);
		}
		int n = adjacentPairs.size() + 1;
		vector<int> answer(n);
		for (auto& [e, adj] : mp) {
			if (adj.size() == 1) {
				answer[0] = e;
				break;
			}
		}
		answer[1] = mp[answer[0]][0];
		for (int i = 2; i < n; i++) {
			auto& adj = mp[answer[i - 1]];
			answer[i] = answer[i - 2] == adj[0] ? adj[1] : adj[0];
		}
		return answer;
	}
};