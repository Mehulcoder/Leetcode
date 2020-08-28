class Solution {
public:
	vector<int> dp1, dp2;

	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int findNumberOfLIS(vector<int>& nums) {
		int n = nums.size();
		dp1.resize(n, 1);
		dp2.resize(n, 1);

		int ans = 1, anss = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i])
					dp1[i] = max(dp1[i], 1 + dp1[j]);
			}
			int count = 0;
			for (int j = 0; j < i; ++j) {
				if (dp1[j] == dp1[i] - 1 && nums[j] < nums[i]) count += dp2[j];
			}
			dp2[i] = max(count, dp2[i]);
			ans = max(ans, dp1[i]);
		}

		for (int i = 0; i < n; ++i) {
			if (dp1[i] == ans) anss += dp2[i];
		}

		return anss;

	}
};