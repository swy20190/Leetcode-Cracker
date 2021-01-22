#include <vector>

using namespace std;

class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> answer;
		for (auto& ast : asteroids) {
			if (ast > 0) {
				answer.push_back(ast);
			}
			else {
				bool survive = true;
				while (!answer.empty() && answer.back() > 0) {
					int curr = answer.back();
					if (curr > -ast) {
						survive = false;
						break;
					}
					else if (curr == -ast) {
						survive = false;
						answer.pop_back();
						break;
					}
					else {
						survive = true;
						answer.pop_back();
					}
				}
				if (survive) {
					answer.push_back(ast);
				}
			}
		}
		return answer;
	}
};