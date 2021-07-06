#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
	unordered_map<int, unordered_map<string, int>> table;
	unordered_map<string, int> vis;

	vector<vector<string>> displayTable(vector<vector<string>>& orders)
	{
		for (auto &vec : orders)
		{
			int tid = stoi(vec[1]);
			int len = vec.size();
			for (int i = 2; i < len; ++i)
			{
				++table[tid][vec[i]];
				if (!vis.count(vec[i]))
					vis[vec[i]] = 1;
			}
		}
		vector<string>first_row;
		for (auto &[k, v] : vis)
		{
			first_row.emplace_back(k);
		}
		sort(first_row.begin(), first_row.end());
		vector<vector<string>>ans;

		for (auto &[tid, cnts] : table)
		{
			vector<string> t = { to_string(tid) };
			for (auto &cai : first_row)
			{
				t.push_back({ to_string((cnts.count(cai) ? cnts[cai] : 0)) });
			}
			ans.emplace_back(t);
		}
		sort(ans.begin(), ans.end(), [](const vector<string>&a, const vector<string>&b)
		{
			return stoi(a[0]) < stoi(b[0]);
		});
		ans.insert(ans.begin(), first_row);
		ans[0].insert(ans[0].begin(), "Table");
		return ans;
	}
};