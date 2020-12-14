#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> answer;
		map<string, vector<string>> map;
		for (auto key : strs) {
			string v = key;
			sort(key.begin(), key.end());
			map[key].push_back(v);
		}
		for (auto pair : map) {
			answer.push_back(pair.second);
		}
		return answer;
	}
};