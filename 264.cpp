class Solution {
public:
	vector<int> dp;
	int nthUglyNumber(int n) {
		dp.resize(n, 0);
		dp[0] = 1;
		int pt2 = 0; int pt3 = 0; int pt5 = 0;
		for (int i = 1; i < n; ++i) {
			dp[i] = min({dp[pt2] * 2, dp[pt3] * 3, dp[pt5] * 5});
			if (dp[i] == dp[pt2] * 2) pt2++;
			else if (dp[i] == dp[pt3] * 3) pt3++;
			else if (dp[i] == dp[pt5] * 5) pt5++;
		}
		for (int i = 0; i < n; ++i) {
			cout << dp[i] << ' ';
		}
		cout << '\n';
		return dp[n - 1];
	}
};