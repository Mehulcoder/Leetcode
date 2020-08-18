class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        if (sum & 1) return 0;
        vector<unordered_set<int>> dp(n + 1);
        dp[0].insert(0);
        for (int i = 0; i < n; i++)
            for (int s : dp[i]) {
                if (s == sum / 2) return 1;
                if (s > sum / 2) continue;
                dp[i + 1].insert(s);
                dp[i + 1].insert(s + nums[i]);
            }
        return 0;
    }
};