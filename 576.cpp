class Solution {
public:

	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int mm, nn, NN;
	int dp[51][51][51];
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int MOD = 1e9 + 7;
	int get(int i, int j, int moves) {
		int outOfBound = (i < 0 || j >= nn || j < 0 || i >= mm);

		if (moves == 0) return outOfBound;
		if (outOfBound) return 1;

		int &ans = dp[i][j][moves];
		if (ans != -1) return ans;

		ans = 0;
		for (int k = 0; k < 4; ++k) {
			ans = (ans + get(i + dx[k], j + dy[k], moves - 1)) % MOD;
		}

		return ans;
	}

	int findPaths(int m, int n, int N, int i, int j) {
		memset(dp, -1, sizeof(dp));
		mm = m; nn = n; NN = N;
		return get(i, j, NN);
	}
};