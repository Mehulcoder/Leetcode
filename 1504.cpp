class Solution {
public:
	int m, n;

	int numSubmat(vector<vector<int>>& mat) {
		n = mat.size();
		if (n == 0) return 0;
		m = mat[0].size();

		for (int i = 0; i < n; ++i) {
			for (int j = m - 1; j >= 0; --j) {
				if (mat[i][j] == 0) continue;
				if (j != m - 1) {
					mat[i][j] += mat[i][j + 1];
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int prevMin = mat[i][j];
				for (int height = 1; height <= min(n - i, n); ++height) {
					prevMin = min(mat[i + height - 1][j], prevMin);
					if (prevMin == 0) break;
					ans += prevMin;
				}
			}
		}

		return ans;

	}
};