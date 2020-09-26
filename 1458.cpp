class Solution {
public:

	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	using ll = long long int;
	ll dp[501][501];
	ll get(int enda, int endb, vector<int> &a, vector<int> &b) {
		if (enda < 0 || endb < 0) return INT_MIN;

		ll &ans = dp[enda][endb];
		if (ans != -1) return ans;

		ll poss1 = a[enda] * b[endb] + max(0ll, get(enda - 1, endb - 1, a, b));
		ll poss2 = get(enda - 1, endb, a, b);
		ll poss3 = get(enda, endb - 1, a, b);

		return ans = max({poss1, poss2, poss3});
	}

	int maxDotProduct(vector<int>& a, vector<int>& b) {
		memset(dp, -1, sizeof(dp));
		return (int)get(a.size() - 1, b.size() - 1, a, b);
	}
};