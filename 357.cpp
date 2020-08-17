class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		int dp[9] = {0}, pre[9] = {0}, curr = 9;
		dp[1] = 9, pre[1] = 10, pre[0] = 1, dp[0] = 1;
		for (int i = 2; i <= 8; ++i) {
			dp[i] = dp[i - 1] * curr--;
			pre[i] = dp[i] + pre[i - 1];
		}

		return pre[n];
	}
};