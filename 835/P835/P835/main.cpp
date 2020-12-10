#include <vector>

using namespace std;


class Solution {
public:
	int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
		int size = img1.size();
		int conj = 0;
		int **img3 = new int*[3 * size];
		for (int i = 0; i < 3 * size; i++) {
			img3[i] = new int[3 * size];
		}
		int nSize = 3 * size;
		for (int i = 0; i < nSize; i++) {
			for (int j = 0; j < nSize; j++) {
				img3[i][j] = 0;
			}
		}
		for (int i = size; i < 2 * size; i++) {
			for (int j = size; j < 2 * size; j++) {
				img3[i][j] = img1[i - size][j - size];
			}
		}
		for (int i = 0; i < 2*size; i++) {
			for (int j = 0; j < 2*size; j++) {
				int tmp = 0;
				for (int r = 0; r<size; r++) {
					for (int c = 0; c < size; c++) {
						tmp += img3[i+r][j+c] * img2[r][c];
					}
				}
				if (tmp > conj) {
					conj = tmp;
				}
			}
		}
		return conj;
	}
};