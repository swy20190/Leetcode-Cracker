#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> stone_heap;
		for (auto stone : stones) {
			stone_heap.push(stone);
		}
		while (stone_heap.size() > 1) {
			int stone_1 = stone_heap.top();
			stone_heap.pop();
			int stone_2 = stone_heap.top();
			stone_heap.pop();
			int diff = stone_1 - stone_2;
			if (diff != 0) {
				stone_heap.push(diff);
			}
		}
		if (stone_heap.empty()) {
			return 0;
		}
		else {
			return stone_heap.top();
		}
	}
};