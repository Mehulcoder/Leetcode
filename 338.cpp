class Solution {
public:
	vector<int> dp;
	vector<int> countBits(int num) {
		dp.resize(num + 1, 0);
		int offset = 1,  curr = 1, count = 0;
		while (curr <= num) {
			if (count == offset) offset = curr, count = 0;
			dp[curr] = dp[curr - offset] + 1;
			curr++, count++;
		}

		return dp;
	}
};