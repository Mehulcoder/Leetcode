class Solution {
public:
	int n;
	vector<int>dp0, dp1;
	int minimumTotal(vector<vector<int>>& triangle) {
		n = triangle.size();
		dp0.resize(n, 0);
		dp1.resize(n, 0);
		for (int i = 0; i < n; ++i)
			dp0[i] = triangle[n - 1][i];

		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j <= i; ++j)
				dp1[j] = triangle[i][j] + min(dp0[j], dp0[j + 1]);
			dp0 = dp1;
		}

		return dp0[0];
	}
};