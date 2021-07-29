#include <vector>
#include <string>

using namespace std;

class OrderedStream {
private:
	int n;
	int ptr = 1;
	string arr[1001] = { "" };
public:
	OrderedStream(int n) {
		ptr = 1;
	}

	vector<string> insert(int idKey, string value) {
		arr[idKey] = value;
		vector<string> answer;
		if (idKey == ptr) {
			while (arr[ptr] != "") {
				answer.push_back(arr[ptr]);
				ptr++;
			}
		}
		return answer;
	}
};