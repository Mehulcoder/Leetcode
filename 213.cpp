class Solution {
public:
	vector<vector<int>> dp;

	int get(vector<int> &num) {

		int n = num.size(), ans = 0;
		if (n == 0) return 0;
		if (n == 1) return num[0];
		dp.clear();
		dp.resize(2, vector<int>(n, 0));

		dp[0][0] = 0; dp[1][0] = num[0];
		dp[0][1] = num[0]; dp[1][1] = num[1];
		ans = max(num[0], num[1]);

		for (int i = 2; i < n; ++i) {
			dp[1][i] = num[i] + max(dp[0][i - 2], dp[1][i - 2]);
			dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
			ans = max({ans, dp[1][i], dp[0][i]});
		}

		return ans;
	}

	int rob(vector<int>& nums) {
		vector<int> nums1, nums2;
		for (int i = 0; i + 1 < nums.size(); ++i) {
			nums1.push_back(nums[i]);
		}

		for (int i = 1; i < nums.size(); ++i) {
			nums2.push_back(nums[i]);
		}

		return max(get(nums1), get(nums2));


	}
};