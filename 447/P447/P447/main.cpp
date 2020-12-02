#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int answer = 0;
		int len = points.size();
		long **dist = new long*[len];
		for (int i = 0; i < len; i++) {
			dist[i] = new long[len];
		}

		if (len == 0||len == 1) {
			return 0;
		}
		for (int i = 0; i < len ; i++) {
			unordered_map<long, int> cnt_map;
			for (int j = i+1; j < len; j++) {
				
				
				long sq = (points[i][0] - points[j][0])*(points[i][0] - points[j][0]) + (points[i][1] - points[j][1])*(points[i][1] - points[j][1]);
				dist[i][j] = sq;
				dist[j][i] = sq;
			}
			for (int k = 0; k < len; k++) {
				unordered_map<long, int>::iterator iter = cnt_map.find(dist[i][k]);
				if (iter == cnt_map.end()) {
					cnt_map.insert(unordered_map<long, int>::value_type(dist[i][k], 1));
				}
				else {
					answer += iter->second * 2;
					iter->second++;
				}
			}
		}
		
		
		return answer;
	}

	
};