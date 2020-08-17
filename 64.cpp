class Solution {
public:
	int m, n;
	vector<vector<int>> dp;
	int get(vector<vector<int>> &grid, int i, int j) {
		if (i == n - 1 && j == m - 1) return grid[i][j];

		int &ans = dp[i][j];
		if (ans != -1) return ans;

		int temp = INT_MAX;
		if (j + 1 < m) temp = min(temp, grid[i][j] + get(grid, i, j + 1));
		if (i + 1 < n) temp = min(temp, grid[i][j] + get(grid, i + 1, j));

		ans = temp;
		return ans;
	}

	int minPathSum(vector<vector<int>>& grid) {
		n = grid.size(), m = grid[0].size();
		dp.resize(n, vector<int>(m, -1));
		return get(grid, 0, 0);
	}
};