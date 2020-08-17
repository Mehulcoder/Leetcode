class Solution {
public:
	int n, m;
	vector<vector<int>> dp;
	int get(vector<vector<int>> &obstacleGrid, int i, int j) {
		if (i == n - 1 && j == m - 1) return !obstacleGrid[i][j];
		if (obstacleGrid[i][j] == 1) return 0;
		int &ans = dp[i][j];
		if (ans != -1) return ans;

		int temp = 0;
		if (i + 1 < n && obstacleGrid[i + 1][j] != 1) temp += get(obstacleGrid, i + 1, j);
		if (j + 1 < m && obstacleGrid[i][j + 1] != 1) temp += get(obstacleGrid, i, j + 1);

		return ans = temp;
	}

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		n = obstacleGrid.size(), m = obstacleGrid[0].size();
		dp.resize(n, vector<int>(m, -1));
		return (get(obstacleGrid, 0, 0));
	}
};