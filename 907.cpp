class Solution {
public:

	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	using pii = pair<int, int>;
	using ll = long long;
	const ll mod = 1000000007;
	int sumSubarrayMins(vector<int>& a) {
		ll ans = 0, n = a.size();
		stack<int> s;
		vector <pii> lr(n);

		for (int i = 0; i < n; ++i) {
			lr[i].first = -1;
			lr[i].second = n;
		}

		for (int i = 0; i < n; ++i) {
			while (!s.empty() && a[i] < a[s.top()]) {
				int curr = s.top();
				s.pop();
				lr[curr].second = i;
				if (!s.empty()) lr[curr].first = s.top();
			}
			s.push(i);
		}

		while (!s.empty()) {
			int curr = s.top();
			s.pop();
			if (!s.empty()) lr[curr].first = s.top();
		}

		for (int i = 0; i < n; ++i) {
			ans = (ans + (a[i] * (i - lr[i].first) * (lr[i].second - i)) % mod) % mod;
			ans %= mod;
		}


		return ans;
	}
};
