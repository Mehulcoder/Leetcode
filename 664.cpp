class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}
	using ll = long long int;

	string str;
	ll n;
	vector<vector<ll>> dp;

	ll get(ll start, ll end) {
		if (start == end) return 1;

		ll &ans = dp[start][end];
		if (ans != -1) return ans;

		ans = INT_MAX;
		for (ll k = start; k < end; ++k) {
			ll sub = (str[start] == str[end]);
			ans = min(ans, get(start, k) + get(k + 1, end) - sub);
		}

		return ans;
	}

	int strangePrinter(string s) {
		n = s.size();
		str = s;
		if (!n) return 0;
		dp.resize(n, vector<ll>(n, -1));

		return (int)get(0, n - 1);
	}
};