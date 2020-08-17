class Solution {
public:
	int n, m;
	vector<int> prevRow, currRow;

	int maximalSquare(vector<vector<char>>& matrix) {
		n = matrix.size();
		if (n == 0) return 0;
		m = matrix[0].size();
		prevRow.resize(m, 0);
		currRow = prevRow;

		int ans = 0;
		for (int j = 0; j < m; ++j) {
			prevRow[j] = matrix[0][j] - '0';
			ans = max(ans, prevRow[j]);
		}

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (matrix[i][j] == '0') currRow[j] = 0;
				else if (j == 0) currRow[j] = matrix[i][j] - '0';
				else currRow[j] = 1 + min({prevRow[j], currRow[j - 1], prevRow[j - 1]});
				ans = max(ans, currRow[j]);
			}
			prevRow = currRow;
		}

		return ans * ans;
	}
};