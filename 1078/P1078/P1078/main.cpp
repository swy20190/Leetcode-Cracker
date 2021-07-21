#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
	vector<string> findOcurrences(string text, string first, string second) {
		istringstream iss(text);
		vector<string> cache;
		string tmp;
		while (iss >> tmp) {
			cache.push_back(tmp);
		}
		vector<string> res;
		for (int i = 0; i < cache.size() - 2; i++) {
			if (cache[i] == first && cache[i + 1] == second) {
				res.push_back(cache[i + 2]);
			}
		}
		return res;
	}
};