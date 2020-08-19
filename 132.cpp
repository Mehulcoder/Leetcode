class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        // s[0..i](inclusive) needs dp[i] cuts
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
            dp[i] = i;

        for (int center = 0; center < n; center++) {
            int l, r; // left bound, right bound of a palindrome
            // odd case
            l = r = center;
            while (l >= 0 && r < n && s[l] == s[r]) {
                dp[r] = min(dp[r], (l - 1 < 0 ? 0 : dp[l - 1] + 1));
                l--; r++;
            }

            // even case
            l = center;
            r = center + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                dp[r] = min(dp[r], (l - 1 < 0 ? 0 : dp[l - 1] + 1));
                l--; r++;
            }

            // only initial value of l, r is different
            // the while loop is totally same
        }

        return dp[n - 1];
    }
};