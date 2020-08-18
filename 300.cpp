class Solution {
public:
	vector<int> dp;
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;
		dp.resize(n, 1);

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[j] <= nums[i]) dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		return *max_element(dp.begin(), dp.end());
	}
};