class Solution {
public:
	bool isPowerOfFour(int num) {
		int start = 1;
		int count = 0;
		for (int i = 0; i < 32; i += 2) {
			if ((start << i)&num == 1)count++;
		}

		return count == 1;
	}
};