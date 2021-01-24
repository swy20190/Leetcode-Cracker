#include <vector>

using namespace std;

class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		int* trust_other = new int[N];
		int* trusted = new int[N];
		for (int i = 0; i < N; i++) {
			trust_other[i] = 0;
			trusted[i] = 0;
		}
		for (auto p : trust) {
			trust_other[p[0]-1]++;
			trusted[p[1]-1]++;
		}
		for (int i = 0; i < N; i++) {
			if (trust_other[i] == 0 && trusted[i] == N-1) {
				return i + 1;
			}
		}
		return -1;
	}
};