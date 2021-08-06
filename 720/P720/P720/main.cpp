#include <vector>
#include <string>
#include <set>
#include <algorithm>


using namespace std;

class Solution {
bool static cmp(string a, string b) {
		if (a.size() == b.size()) {
			return a > b;
		}
		return a.size() < b.size();
	}
public:
	string longestWord(vector<string>& words) {
		set<string> st;
		for (int i = 0; i < words.size(); i++) {
			st.insert(words[i]);
		}
		sort(words.begin(), words.end(), cmp);

		string rec;
		for (int i = words.size() - 1; i >= 0; i--) {
			string tmp = words[i];
			int j = tmp.size();
			while (j--) {
				tmp.pop_back();
				if (st.find(tmp) == st.end()) {
					break;
				}
			}
			if (j == 0) {
				rec = words[i];
				break;
			}
		}
		return rec;
	}
};