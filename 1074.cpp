class Solution {
public:

	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	vector<vector<int>> sum;
	vector<vector<int>> mat;
	int m, n;
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		mat = matrix;
		n = mat.size();
		m = mat[0].size();
		sum.resize(n, vector<int>(m, 0));
		int ans = 0;
		map<int, vector<int>> mm;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				sum[i][j] = mat[i][j];
				int temp = 0;
				if (i - 1 >= 0) {
					sum[i][j] += sum[i - 1][j];
					temp += sum[i - 1][j];

				}
				if (j - 1 >= 0) {
					sum[i][j] += sum[i][j - 1];
					temp += sum[i][j - 1];
				}
				if (i - 1 >= 0 && j - 1 >= 0) {
					sum[i][j] -= sum[i - 1][j - 1];
					temp -= sum[i - 1][j - 1];
				}

				int req = sum[i][j] - target;
				mm[temp].push_back(j);
				int cnt = 0;
				for (int p = 0; p < mm[temp].size(); ++p) {
					if (mm[temp][p] <= j) ans++;
				}

			}
		}

		return ans;
	}
};