#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)

class Solution {
public:
        Solution() {
                ios::sync_with_stdio(false);
                cin.tie(NULL);
                cout.tie(NULL);
        }

        vector < vector<int>> dp;
        int maxProfit(int k, vector<int>& prices) {
                int n = prices.size();
                if (!n) return 0;

                if (k >= n / 2) return get(prices);

                dp.resize(n, vector<int>(k + 1, 0));

                vector<int> maxi(k + 1, 0);
                rep(i, k + 1) {
                        maxi[i] = -prices[0];
                }

                fr(i, 1, n - 1) {
                        fr(j, 0, k) {
                                if (j) dp[i][j] = max(dp[i - 1][j], prices[i] + maxi[j - 1]);
                                maxi[j] = max(maxi[j], dp[i - 1][j] - prices[i]);
                        }
                }

                return dp[n - 1][k];
        }

        int get(vector<int> &prices) {
                int n = prices.size();

                int ans = 0ll;
                fr(i, 1, n - 1) {
                        if (prices[i - 1] <= prices[i]) {
                                ans += (prices[i] - prices[i - 1]);
                        }
                }

                return (int)ans;
        }
};