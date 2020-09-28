class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	using ll = long long int;
	const ll MOD = 1e9 + 7;
	vector<char> v = {'a', 'e', 'i', 'o', 'u'};
	ll dp[20005][5];
	ll get(ll end, ll i) {
		if (end == 0) return 1;

		ll &ans = dp[end][i];
		if (ans != -1) return ans;

		if (i == 0) {
			ans = get(end - 1, 1) + get(end - 1, 2) + get(end - 1, 4);
		} else if (i == 1) {
			ans = get(end - 1, 0) + get(end - 1, 2);
		} else if (i == 2) {
			ans = get(end - 1, 1) + get(end - 1, 3);
		} else if (i == 3) {
			ans = get(end - 1, 2);
		} else if (i == 4) {
			ans = get(end - 1, 2) + get(end - 1, 3);
		}

		return ans = (ans + MOD) % MOD;
	}

	int countVowelPermutation(int n) {
		ll ans = 0;

		memset(dp, -1, sizeof(dp));

		for (ll i = 0; i < v.size(); ++i) {
			ans += get(n - 1, i);
			ans %= MOD;
		}

		return (int)(ans + MOD) % MOD;
	}
};