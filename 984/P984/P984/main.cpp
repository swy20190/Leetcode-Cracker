#include <string>
#include <iostream>


using namespace std;


class Solution {
public:
	string strWithout3a3b(int A, int B) {
		string answer;
		if (A < B) {
			int diff = B - A;
			int tri_num = 0;
			int bi_num = 0;
			for (int i = 0; i < diff - 2; i++) {
				answer.append("bba");
				tri_num++;
			}
			for (int i = 0; i < A-tri_num; i++) {
				answer.append("ba");
				bi_num++;
			}
			for (int i = 0; i < B - 2 * tri_num - bi_num; i++) {
				answer.append("b");
			}
		}
		else {
			int diff = A - B;
			int tri_num = 0;
			int bi_num = 0;
			for (int i = 0; i < diff - 2; i++) {
				answer.append("aab");
				tri_num++;
			}
			for (int i = 0; i < B-tri_num; i++) {
				answer.append("ab");
				bi_num++;
			}
			for (int i = 0; i < A - 2 * tri_num - bi_num; i++) {
				answer.append("a");
			}
			
		}
		return answer;
	}
};

int main() {
	Solution solution;
	cout << solution.strWithout3a3b(4, 1);
}