#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		vector<int> distances;
		for (auto h : houses) {
			if (h <= heaters[0]) {
				distances.push_back(heaters[0] - h);
			}
			else if (h >= heaters[heaters.size() - 1]) {
				distances.push_back(h - heaters[heaters.size() - 1]);
			}
			else {
				for (int i = 0; i < heaters.size(); i++) {
					if (h <= heaters[i]) {
						distances.push_back(min(heaters[i] - h, h - heaters[i - 1]));
						break;
					}
				}
			}
		}
		int answer = INT_MIN;
		for (auto d : distances) {
			answer = max(answer, d);
		}
		return answer;
	}
};