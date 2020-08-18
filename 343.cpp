class Solution {
public:
	vector<int> dp;
	int integerBreak(int n) {
		dp.resize(n + 1, 0);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 1;

		for (int i = 3; i < n + 1; ++i) {
			for (int j = 1; j < i; ++j) {
				dp[i] = max({dp[i], (i - j)*j, dp[i - j]*j});
			}
		}
		for (int i = 0; i < n + 1; ++i) {
			cout << dp[i] << ' ';
		}
		cout << '\n';
		return dp[n];
	}
};