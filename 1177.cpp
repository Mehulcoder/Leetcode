class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    vector<vector<int>> dp;
    vector<bool> ans;
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        dp.resize(26, vector<int>(n, 0));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < 26; ++i) {
                if (j != 0) dp[i][j] = dp[i][j - 1];
            }
            dp[s[j] - 'a'][j]++;
        }

        for (int k = 0; k < queries.size(); ++k) {
            int left = queries[k][0];
            int right = queries[k][1];
            int coin = queries[k][2];

            int oddCount = 0;
            for (int i = 0; i < 26; ++i) {
                int count = dp[i][right];
                if (left > 0) count -= dp[i][left - 1];
                oddCount += count % 2;
            }

            //If length is odd: We'll need one odd freq
            oddCount -= (right - left + 1) % 2;
            if (oddCount % 2 != 0 || oddCount / 2 > coin || oddCount < 0) ans.push_back(0);
            else ans.push_back(1);
        }

        return ans;

    }
};