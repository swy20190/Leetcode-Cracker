#include <queue>

using namespace std;

class RecentCounter {
	queue<int> signals;
public:
	RecentCounter() {

	}

	int ping(int t) {
		signals.push(t);
		while (signals.front() < t - 3000) {
			signals.pop();
		}
		return signals.size();
	}
};
