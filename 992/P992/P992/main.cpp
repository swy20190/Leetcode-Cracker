#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int subarraysWithKDistinct(vector<int>& A, int K) {
		return help(A, K) - help(A, K - 1);
	}

	int help(vector<int>& A, int K) {
		unordered_map<int, int> hash;
		int left = 0;
		int right = 0;
		int answer = 0;
		int len = A.size();
		while (right < len) {
			hash[A[right]]++;
			right++;
			while (hash.size() > K) {
				hash[A[left]]--;
				if (hash[A[left]] == 0) {
					hash.erase(A[left]);
				}
				left++;
			}
			answer += (right - left);
		}
		return answer;
	}
};