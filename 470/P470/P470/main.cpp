// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
	int rand10() {
		int seed = (rand7() - 1) * 7 + (rand7() -1 );
		while (seed >= 40) {
			seed = (rand7() - 1) * 7 + (rand7() - 1);
		}
		return seed % 10 + 1;
	}
};