using ll = long long int;
const ll MOD = 1e9 + 7;
class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	int kConcatenationMaxSum(vector<int>& arr, int k) {
		ll n = arr.size();
		ll mp = 0, ms = 0, sum = 0;
		ll start = 0;
		while (start < n) {
			sum += arr[start];
			mp = max(mp, sum);
			start++;
		}

		start = n - 1; sum = 0;
		while (start >= 0) {
			sum += arr[start];
			ms = max(ms, sum);
			start--;
		}

		ll maxTillNow = 0, maxEndingHere = 0;
		for (ll i = 0; i < n; ++i) {
			maxEndingHere = max(maxEndingHere + arr[i], (ll)arr[i]);
			maxTillNow = max(maxTillNow, maxEndingHere);
		}

		ll ans = maxTillNow;
		if (k > 1) ans = max(ans, ms + mp);
		if (k > 2 && sum > 0) {
			ans = max(ans, ms + mp + (k - 2) * sum);
		}

		ans %= MOD;
		ans = (ans + MOD) % MOD;
		return ans;
	}
};