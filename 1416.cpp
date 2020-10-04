class Solution {
public:
	using ll = long long int;
	const ll MOD = 1e9 + 7;
	string s;
	ll k, n, dp[100005];
	ll get(ll pos) {
		if (pos == n) return 1;

		ll &anss = dp[pos];
		if (anss != -1) return anss;

		ll ans = 0ll, num = 0ll;
		for (int i = pos; i < n; ++i) {
			num = num * 10 + (s[i] - '0');
			if (num > k) break;
			bool flag = 0;
			if (i < n - 1 && s[i + 1] != 0) flag = 1;
			if (num >= 1 && flag) ans += get(i + 1);
		}

		return anss = ans % MOD;
	}

	int numberOfArrays(string ss, int kk) {
		s = ss;
		n = s.size();
		memset(dp, -1, sizeof(dp));
		k = kk;
		return (MOD + get(0)) % MOD;
	}
};