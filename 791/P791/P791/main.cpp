#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string customSortString(string S, string T) {
		int curr_char = 0;
		for (int i = 0; i < S.size(); i++) {
			for (int j = curr_char; j < T.size(); j++) {
				if (T[j] == S[i]) {
					swap(T[j], T[curr_char]);
					curr_char++;
				}
			}
		}
		return T;
	}
};