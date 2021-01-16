#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int distributeCandies(vector<int>& candyType) {
		int sum = candyType.size();
		vector<int> tmp = candyType;
		set<int> s(tmp.begin(), tmp.end());
		int types = s.size();
		return min(sum / 2, types);

	}
};