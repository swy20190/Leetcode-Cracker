#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<int> dis(n + 1, -1);
		dis[k] = 0;
		using Pair = pair<int, int>;
		priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
		pq.emplace(0, k);

		while (!pq.empty()) {
			auto e = pq.top();
			pq.pop();
			if (e.first > dis[e.second])
				continue;
			for (int i = 0; i < times.size(); i++) {
				if (times[i][0] == e.second) {
					int v = times[i][1];
					int w = e.first + times[i][2];
					if (dis[v] == -1 || dis[v] > w) {
						dis[v] = w;
						pq.emplace(w, v);
					}
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (dis[i] == -1) {
				return -1;
			}
			ans = max(ans, dis[i]);
		}
		return ans;
	}
};