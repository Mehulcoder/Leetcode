class Solution {
public:
	vector<int> pre;
	vector<vector<int>> dp;
	int n;
	int get(int start, int m) {
		if (start + 2 * m >= n) {
			int temp = pre[n - 1];
			if (start > 0) temp -= pre[start - 1];
			return temp;
		}

		int &ans = dp[start][m];
		if (ans != -1) return ans;

		int opponent = INT_MAX;
		for (int i = 1; i < 2 * m + 1 && i + start < n; ++i) {
			opponent = min(opponent, get(start + i, max(m, i)));
		}
		int temp = pre[n - 1];
		if (start > 0) temp -= pre[start - 1];
		return ans = temp - opponent;
	}

	int stoneGameII(vector<int>& piles) {
		n = piles.size();
		dp.resize(n, vector<int>(n, -1));
		pre.resize(n, 0);
		for (int i = 0; i < n; ++i) {
			pre[i] = piles[i];
			if (i > 0)pre[i] += pre[i - 1];
		}
		return get(0, 1);
	}
};