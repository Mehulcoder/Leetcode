class Solution {
public:
	std::vector<int> dp;
	int get(int n) {
		if (n <= 1) return 1;
		int &ans = dp[n];
		if (ans != -1) return ans;
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans += (get(i - 1) * get(n - i));
		}

		return ans;
	}

	int numTrees(int n) {
		dp.resize(n + 1, -1);
		return get(n);
	}
};