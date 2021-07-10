#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class TimeMap {
	unordered_map<string, map<int, string>> m;
	
public:
	/** Initialize your data structure here. */
	TimeMap() {

	}

	void set(string key, string value, int timestamp) {
		m[key][timestamp] = value;
	}

	string get(string key, int timestamp) {
		if (m.count(key) == 0) {
			return "";
		}
		auto iter = m[key].upper_bound(timestamp);
		if (iter == m[key].begin()) {
			return "";
		}
		iter--;
		return iter->second;
	}
};
