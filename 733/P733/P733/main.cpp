#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		vector<vector<int>> answer = image;
		if (answer.size() == 0) {
			return answer;
		}
		if (answer[0].size() == 0) {
			return answer;
		}
		inflection(answer, sr, sc, newColor, image[sr][sc]);
		return answer;
	}

	void inflection(vector<vector<int>>& img, int row, int col, int newColor, int oldColor) {
		if (row < 0 || row >= img.size() || col < 0 || col >= img[0].size()||img[row][col] != oldColor||img[row][col] == newColor) {
			return;
		}
		else {
			img[row][col] = newColor;
			inflection(img, row - 1, col, newColor, oldColor);
			inflection(img, row + 1, col, newColor, oldColor);
			inflection(img, row, col - 1, newColor, oldColor);
			inflection(img, row, col + 1, newColor, oldColor);
		}
	}
};