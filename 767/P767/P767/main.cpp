#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reorganizeString(string S) {
		vector<pair<char, int>> h(26, make_pair('a', 0));

		for (int i = 0; i < 26; i++) {
			h[i].first += i;
		}
		for (char c : S) {
			h[c - 'a'].second++;
		}
		sort(h.begin(), h.end(), [](pair<char, int> a, pair<char, int> b) {
			return a.second > b.second;
		});
		if (h[0].second > (S.size() + 1) / 2) {
			return "";
		}

		int size = h[0].second;
		vector<string> ans(size);
		int l = 0;

		for (int i = 0; i < 26; i++) {
			int n = h[i].second;
			for (int j = 0; j < n; j++) {
				ans[l++%size].push_back(h[i].first);
			}
		}
		string res;
		for (int i = 0; i < size; i++) {
			res += ans[i];
		}
		return res;
	}
};