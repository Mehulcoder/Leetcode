class Solution {
public:
	Solution() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
	}

	using ll = long long;
	const ll mod = 1000000007;
	int maxArea(ll h, ll w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		sort(verticalCuts.begin(), verticalCuts.end());
		sort(horizontalCuts.begin(), horizontalCuts.end());

		horizontalCuts.push_back(h);
		verticalCuts.push_back(w);

		int horiMax = horizontalCuts[0];
		int vertiMax = verticalCuts[0];
		for (ll i = 1; i < horizontalCuts.size(); ++i) {
			horiMax = max(horiMax, horizontalCuts[i] - horizontalCuts[i - 1]);
		}


		for (int i = 1; i < verticalCuts.size(); ++i) {
			vertiMax = max(vertiMax, verticalCuts[i] - verticalCuts[i - 1]);
		}

		ll ans = ((horiMax % mod) * (vertiMax % mod)) % mod;

		return ans;
	}
};