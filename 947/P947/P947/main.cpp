#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
	int n = 20005;
	int father[20005];

	void init() {
		for (int i = 0; i < n; i++) {
			father[i] = i;
		}
	}

	int find(int u) {
		if (u == father[u]) {
			return u;
		}
		else {
			father[u] = find(father[u]);
			return father[u];
		}
	}

	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) {
			return;
		}
		father[v] = u;
	}

	bool same(int u, int v) {
		u = find(u);
		v = find(v);
		return u == v;
	}
public:
	int removeStones(vector<vector<int>>& stones) {
		init();
		for (int i = 0; i < stones.size(); i++) {
			join(stones[i][0], stones[i][1] + 10000);
		}
		unordered_map<int, bool> umap;
		for (int i = 0; i < stones.size(); i++) {
			umap[find(stones[i][0])] = true;
			umap[find(stones[i][1] + 10000)] = true;
		}
		return stones.size() - umap.size();
	}
};