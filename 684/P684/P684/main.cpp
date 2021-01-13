#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int nodesCount = edges.size();
		vector<int> parent(nodesCount + 1);
		for (int i = 1; i <= nodesCount; i++) {
			parent[i] = i;
		}
		for (auto& edge : edges) {
			int node1 = edge[0];
			int node2 = edge[1];
			if (_find(parent, node1) != _find(parent, node2)) {
				_union(parent, node1, node2);
			}
			else {
				return edge;
			}
		}
		return vector<int>{};
	}

	int _find(vector<int>& parent, int index) {
		if (parent[index] != index) {
			parent[index] = _find(parent, parent[index]);
		}
		return parent[index];
	}

	void _union(vector<int>& parent, int index1, int index2) {
		parent[_find(parent, index1)] = _find(parent, index2);
	}
};