class Solution {
public:
	int n;
	vector<vector<int>> arr;
	vector<vector<int>> dp;
	int get(int row, int col) {
		if (row >= n) return 0;

		auto &ans = dp[row][col];
		if (ans != 100000) return ans;

		int temp = INT_MAX;
		for (int j = 0; j < n; ++j) {
			if (j == col) continue;
			temp = min(temp, get(row + 1, j));
		}

		return ans = temp + arr[row][col];
	}

	int minFallingPathSum(vector<vector<int>>& ar) {
		arr = ar;
		n = ar.size();

		dp.resize(n, vector<int>(n, 100000));
		int  anss = INT_MAX;
		for (int i = 0; i < n; ++i) {
			anss = min(anss, get(0, i));
		}

		return anss;
	}
};