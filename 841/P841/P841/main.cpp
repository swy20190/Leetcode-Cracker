#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		vector<int> visited(rooms.size(), 0);
		visited[0] = 1;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int key = q.front();
			q.pop();
			vector<int> keys = rooms[key];
			for (auto key : keys) {
				if (!visited[key]) {
					q.push(key);
					visited[key] = 1;
				}
			}
		}
		for (auto v : visited) {
			if (v == 0) {
				return false;
			}
		}
		return true;
	}
};