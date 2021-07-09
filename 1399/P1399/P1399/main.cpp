#include <iostream>

using namespace std;

class Solution {
	int cal_sum(int n) {
		int sum = 0;
		if (n == 10000) {
			return 1;
		}
		if (n >= 1000) {
			sum += n / 1000;
			n = n % 1000;
		}
		if (n >= 100) {
			sum += n / 100;
			n = n % 100;
		}
		if (n >= 10) {
			sum += n / 10;
			n = n % 10;
		}
		sum += n;
		return sum;
	}
public:
	int countLargestGroup(int n) {
		int bucket[37] = { 0 };
		for (int i = 1; i <= n; i++) {
			bucket[cal_sum(i)]++;
		}
		int maxCalSum = INT_MIN;
		for (int i = 0; i < 37; i++) {
			if (bucket[i] > maxCalSum) {
				maxCalSum = bucket[i];
			}
		}
		int answer = 0;
		for (int i = 0; i < 37; i++) {
			if (bucket[i] ==  maxCalSum) {
				answer++;
			}
		}
		return answer;
	}
};