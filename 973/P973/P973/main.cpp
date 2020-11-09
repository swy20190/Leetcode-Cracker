#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {

	struct cmp {
		bool operator() (vector<int> node_a, vector<int> node_b) {
			return node_a[0] * node_a[0] + node_a[1] * node_a[1] > node_b[0] * node_b[0] + node_b[1] * node_b[1];
		}
	};
public:
	vector<vector<int> > kClosest(vector<vector<int> >& points, int K) {
		priority_queue<vector<int>, vector<vector<int> >, cmp> p_q;
		vector<vector<int> > answer;
		int len = points.size();
		for (int i = 0; i < len; i++) {
			p_q.push(points[i]);
		}
		for (int i = 0; i < K; i++) {
			answer.push_back(p_q.top());
			p_q.pop();
		}

		return answer;
	}
};

int main() {
	vector<vector<int>> test;
	vector<int> p1;
	vector<int> p2;
	p1.push_back(114);
	p1.push_back(514);
	p2.push_back(1919);
	p2.push_back(810);
	test.push_back(p1);
	test.push_back(p2);
	Solution solution;
	cout << solution.kClosest(test, 1)[0][1];
}