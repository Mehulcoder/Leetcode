using ll = long long int;

class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	string s;
	ll n;
	vector<vector<ll>> dp;
	ll getCost(string &str) {
		int m = str.size();
		ll ans = 0ll;
		for (int i = 0; i < m / 2; ++i) {
			if (str[i] != str[m - i - 1]) ans++;
		}

		return ans;
	}

	ll get(ll end, ll count) {
		if (end < 0 && count <= 0) return 0;
		if (end < 0 && count >= 1) return INT_MAX;
		if (end >= 0 && count <= 0) return INT_MAX;
		if (end < count - 1) return INT_MAX;
		if (end == count - 1) return 0;

		ll &anss = dp[end][count];
		if (anss != -1) return anss;

		ll ans = INT_MAX;
		for (ll i = count - 1; i <= end; ++i) {
			string temp = s.substr(i, end - i + 1);
			ll cost = getCost(temp);
			ans = min(ans, cost + get(i - 1, count - 1));
		}

		return anss = ans;
	}

	int palindromePartition(string S, int K) {
		s = S;
		n = s.size();
		dp.resize(n + 1, vector<ll>(n + 1, -1));
		return (int)get(n - 1, K);
	}
};