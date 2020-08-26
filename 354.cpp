class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        sort(nums.begin(), nums.end());
        vector<int> ret(n, 1);
        int res = 1;
        for (int i = 0; i < n; i ++) {
            for (int j = i - 1; j >= 0; j --) {
                if (nums[j][0] < nums[i][0] && nums[j][1] < nums[i][1])
                    ret[i] = max(ret[i], ret[j] + 1);
            }
            res = max(res, ret[i]);
        }
        return res;
    }
};