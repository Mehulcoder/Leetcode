class Solution {
public:
	using ll = long long int;
	using pii = pair<ll, ll>;
	ll dp[105][105];
	vector<vector<pii>> edges;
	ll nn, desti;

	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	ll get(ll root, ll stops) {
		if (stops >= -1 && root == desti) return 0;
		if (stops <= -1) return INT_MAX;

		ll &ans = dp[root][stops];
		if (ans != -1) return ans;

		ans = INT_MAX;
		for (auto &child : edges[root]) {
			ans = min(ans, child.second + get(child.first, stops - 1));
		}

		return ans;
	}

	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
		edges.resize(n);
		nn = n;
		desti = dst;
		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < flights.size(); ++i) {
			edges[flights[i][0]].push_back({flights[i][1], flights[i][2]});
		}

		ll ans = get(src, K);
		return (ans >= INT_MAX ? -1 : ans);
	}
};