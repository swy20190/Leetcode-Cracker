#include <vector>
#include <alg.h>

using namespace std;

class Solution {
public:
	vector<int> pathInZigZagTree(int label) {
		vector<int> answer;
		while (label) {
			int parent = label / 2;
			int x = parent;
			int cnt = 0;
			while (x / 2) {
				x /= 2;
				cnt++;
			}
			answer.push_back(label);
			if (label == 1) {
				break;
			}
			else {
				label = pow(2, cnt + 1) - 1 - parent + pow(2, cnt);
			}
		}
		reverse(answer.begin(), answer.end());
		return answer;
	}
};