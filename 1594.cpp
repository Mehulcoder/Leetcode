#define f first
#define s second
using ll = long long int;
using pii = pair<ll, ll>;
const ll MOD = 1e9 + 7;

class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int n, m;
	vector<vector<pii>> dp;

	int maxProductPath(vector<vector<int>>& grid) {
		n = grid.size();
		if (!n) return 0;
		m = grid[0].size();

		dp.resize(n, vector<pii>(m));

		//Fill up the base case
		for (int i = 0; i < n; ++i) {
			dp[i][0] = {grid[i][0], grid[i][0]};
			if (i > 0) dp[i][0].f *= dp[i - 1][0].f;
			if (i > 0) dp[i][0].s *= dp[i - 1][0].f;
		}

		for (int j = 0; j < m; ++j) {
			dp[0][j] = {grid[0][j], grid[0][j]};
			if (j > 0) dp[0][j].f *= dp[0][j - 1].f;
			if (j > 0) dp[0][j].s *= dp[0][j - 1].f;
		}


		//Fill up the dp
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				ll temp1 = dp[i - 1][j].f * grid[i][j];
				ll temp2 = dp[i - 1][j].s * grid[i][j];
				ll temp3 = dp[i][j - 1].f * grid[i][j];
				ll temp4 = dp[i][j - 1].s * grid[i][j];

				dp[i][j].f = min({temp1, temp2, temp3, temp4});
				dp[i][j].s = max({temp1, temp2, temp3, temp4});
			}
		}

		int ans = dp[n - 1][m - 1].s % MOD;
		return ((ans < 0) ? -1 : ans);
	}
};