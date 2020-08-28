class Solution {
public:
	long long int n;
	vector<vector<long long int>> dp;
	long long int get(long long int i, long long int j, vector<vector<int>> &A) {
		if (i == n - 1) return A[i][j];

		long long int &ans = dp[i][j];
		if (ans != -1) return ans;

		ans = INT_MAX;
		ans = min(ans, A[i][j] + get(i + 1, j, A));
		if (j + 1 < n)
			ans = min(ans, A[i][j] + get(i + 1, j + 1, A));
		if (j - 1 >= 0)
			ans = min(ans, A[i][j] + get(i + 1, j - 1, A));
		return ans;
	}

	int minFallingPathSum(vector<vector<int>>& A) {
		n = A.size();
		dp.resize(n, vector<long long int>(n, -1));
		long long int ans = INT_MAX;
		for (long long int i = 0; i < n; ++i) {
			ans = min(ans, get(0, i, A));
		}

		return (int)ans;
	}
};