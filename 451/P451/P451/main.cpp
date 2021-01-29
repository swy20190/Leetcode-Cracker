#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;


class Solution {
public:
	bool cmp(pair<char, int> x, pair<char, int> y) {
		return x.second < y.second;
	}

	
	string frequencySort(string s) {
		unordered_map<char, int> hash;
		for (int i = 0; i < s.size(); i++) {
			hash[s[i]]++;
		}
		vector<pair<char, int>> v;
		for (auto p : hash) {
			v.push_back(p);
		}
		sort(v.begin(), v.end(), cmp);
		string answer = "";
		for (auto p : v) {
			for (int i = 0; i < p.second; i++) {
				answer += p.first;
			}
		}
		return answer;
	}
};