class Solution {
public:

	int recur(int l, int r, vector<vector<int>>&dp) {
		if (l >= r) //If n=1 ans=0 as I know he would have guesses that number only
			return 0;
		if (dp[l][r] != -1)
			return dp[l][r];
		int ans = 10000;
		for (int i = l; i <= r; i++) {
			int k = max(i + recur(i + 1, r, dp), i + recur(l, i - 1, dp));
			ans = min(ans, k);
		}
		return dp[l][r] = ans;
	}
	int getMoneyAmount(int n) {
		vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
		return recur(1, n, dp);
	}
};