class NumMatrix {
public:
	vector<vector<int>> sums;
	int n, m;
	NumMatrix(vector<vector<int>>& matrix) {
		sums = matrix;
		n = sums.size();
		if (n == 0)m = 0;
		else m = matrix[0].size();

		//Fill the top row
		for (int i = 1; i < m; ++i) {
			sums[0][i] += sums[0][i - 1];
		}
		//Fill leftmost column
		for (int i = 1; i < n; ++i) {
			sums[i][0] += sums[i - 1][0];
		}

		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				sums[i][j] += sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
			}
		}

	}

	int sumRegion(int row1, int col1, int row2, int col2) {

		int ans = sums[row2][col2];
		if (col1 > 0)ans -= sums[row2][col1 - 1];
		if (row1 > 0)ans -= sums[row1 - 1][col2];
		if (row1 > 0 && col1 > 0)ans += sums[row1 - 1][col1 - 1];
		return ans;
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */