class Solution {
public:
	using ll = long long int;
	vector<int> a, b;
	ll dp[2005][2005];
	int n, m;
	ll get(int i, int j, int next) {
		if (i < 0) return 0;

		if (j < 0) {
			if (a[i] >= next) return INT_MAX;
			else return get(i - 1, m - 1, a[i]);
		}

		ll &ans = dp[i][j];
		if (ans != -1) return ans;

		ll temp = INT_MAX;
		if (a[i] >= next) {
			j = lower_bound(b.begin(), b.end(), next) - b.begin() - 1;
			if (j < 0) temp = INT_MAX;
			else temp = 1 + get(i - 1, j - 1, b[j]);
		} else {
			int  J = j;
			J = lower_bound(b.begin(), b.end(), next) - b.begin() - 1;
			if (J < 0) temp = get(i - 1, J, a[i]);
			else temp = min(1 + get(i - 1, J - 1, b[J]), get(i - 1, j, a[i]));
		}

		return ans = temp;
	}

	int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
		n = arr.size(), m = arr2.size();
		a = arr1;
		b = arr2;
		sort(b.begin(), b.end());
		memset(dp, -1, sizeof(dp));
		ll ans = get(a.size() - 1, b.size() - 1, INT_MAX);
		return (ans >= INT_MAX - 10) ? (-1) : ans;
	}
};