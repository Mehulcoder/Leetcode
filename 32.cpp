class Solution {
public:
	vector<int> dp;
	int longestValidParentheses(string s) {
		int n = s.size(), ans = 0;
		if (n == 0) return 0;
		dp.resize(n, 0);

		dp[0] = 0;
		for (int i = 1; i < n; ++i) {
			if (s[i] == ')' && (i - dp[i - 1] - 1) >= 0 && s[i - dp[i - 1] - 1] == '(') {
				dp[i] = 2 + dp[i - 1];
				if (i - dp[i] >= 0) dp[i] += dp[i - dp[i]];
				ans = max(ans, dp[i]);
			}
		}

		return ans;
	}
};