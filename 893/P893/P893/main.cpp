#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int numSpecialEquivGroups(vector<string>& A) {
		unordered_set<string> Set;
		for (const auto &str : A) {
			string even, odd;
			for (int i = 0; i < str.size(); i++) {
				if (i % 2)
					odd += str[i];
				else
					even += str[i];
			}
			sort(even.begin(), even.end());
			sort(odd.begin(), odd.end());
			Set.insert(odd + even);
		}
		return Set.size();
	}
};

