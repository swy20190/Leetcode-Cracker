#include <vector>

using namespace std;

class Solution {
	void dfs(vector<vector<int>> & graph, int v, vector<vector<int>> &res, vector<int>& path) {
		for (auto val : graph[v]) {
			path.push_back(val);
			if (val == graph.size() - 1) {
				res.push_back(path);
			}
			else {
				dfs(graph, val, res, path);
			}
			path.pop_back();
		}
	}
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> res;
		vector<int> path;
		path.push_back(0);
		dfs(graph, 0, res, path);
		return res;
	}
};