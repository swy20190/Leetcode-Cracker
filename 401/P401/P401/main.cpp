#include <vector>
#include <string>
#include <bitset>

using namespace std;

class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> answer;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 60; j++) {
				if (bitset<32>(i).count() + bitset<32>(j).count() == num) {
					answer.push_back(to_string(i) + ":" + (j < 10 ? "0" : "") + to_string(j));
				}
			}
		}
		return answer;
	}
};