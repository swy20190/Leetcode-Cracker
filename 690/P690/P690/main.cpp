#include <vector>
#include <unordered_map>

using namespace std;


class Employee {
public:
	int id;
	int importance;
	vector<int> subordinates;
};


class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		if (employees.empty()) {
			return 0;
		}
		unordered_map<int, Employee*> id_map;
		for (auto em : employees) {
			id_map[em->id] = em;
		}
		return getSum(id_map[id], id_map);
	}

	int getSum(Employee* e, unordered_map<int, Employee*>& map) {
		int sub = e->importance;
		for (auto s : e->subordinates) {
			sub += getSum(map[s], map);
		}
		return sub;
	}
};